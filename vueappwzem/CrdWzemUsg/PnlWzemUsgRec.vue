<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="9">
					<div class="caption text-decoration-underline">{{tag.Cpt}}</div>
					<div>{{continf.TxtRef}}</div>
				</v-col>
				<v-col cols="3" align="end">
					<v-btn
						v-if="statshr.srefIxWzemVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeCLick')"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					<v-btn
						v-if="statshr.srefIxWzemVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						:disabled="!statshr.ButRegularizeActive"
						v-on:click="handleButClick('ButRegularizeClick')"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzemVExpstate=='regd'"
		>
			<v-row>
				<v-col cols="12" md="12">
					<PnlWzemUsgDetail
						v-on:request="handleRequest"
						ref="PnlWzemUsgDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWzemUsgAAccess
						v-on:request="handleRequest"
						ref="PnlWzemUsgAAccess"
						:scrJref=statshr.scrJrefAAccess
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWzemUsgMNUser
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemUsgMNUser"
						:scrJref=statshr.scrJrefMNUser
					/>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	*/
	import PnlWzemUsgDetail from './PnlWzemUsgDetail';
	import PnlWzemUsgAAccess from './PnlWzemUsgAAccess';
	import PnlWzemUsgMNUser from './PnlWzemUsgMNUser';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzemUsgRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemUsgDetail,
			PnlWzemUsgAAccess,
			PnlWzemUsgMNUser
			/*
			*/
		},

		mounted() {
			//console.log("PnlWzemUsgRec.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzemInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWzemUsgRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzemUsgRec) this.continf = dpcheng.ContInfWzemUsgRec;
				if (dpcheng.StatAppWzemUsgRec) this.statapp = dpcheng.StatAppWzemUsgRec;
				if (dpcheng.StatShrWzemUsgRec) this.statshr = dpcheng.StatShrWzemUsgRec;
				if (dpcheng.TagWzemUsgRec) {
					Wzem.unescapeBlock(dpcheng.TagWzemUsgRec);
					this.tag = dpcheng.TagWzemUsgRec;
				}
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				//console.log(obj);
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
					else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzemVDpch, obj.dpcheng);

				} else if (this.initdone) {
					if (this.statshr.srefIxWzemVExpstate == "regd") {
						/*
						*/
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzemUsgDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWzemUsgAAccess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNUser) this.$refs.PnlWzemUsgMNUser.handleReply(obj);
						/*
						*/
					}
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzemVDpch, dpcheng) {
				if (srefIxWzemVDpch == "DpchEngWzemUsgRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzemVDpch == "DpchEngWzemUsgRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWzemVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzemUsgDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWzemUsgAAccess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNUser) this.$refs.PnlWzemUsgMNUser.handleUpdate(obj);
						/*
						*/
						else processed = false;
					}
				}

				return processed
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
