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
					<PnlWzemUsrDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemUsrDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWzemUsrAAccess
						v-on:request="handleRequest"
						ref="PnlWzemUsrAAccess"
						:scrJref=statshr.scrJrefAAccess
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWzemUsr1NSession
						v-on:request="handleRequest"
						ref="PnlWzemUsr1NSession"
						:scrJref=statshr.scrJref1NSession
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWzemUsrMNUsergroup
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemUsrMNUsergroup"
						:scrJref=statshr.scrJrefMNUsergroup
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
	import PnlWzemUsrDetail from './PnlWzemUsrDetail';
	import PnlWzemUsrAAccess from './PnlWzemUsrAAccess';
	import PnlWzemUsr1NSession from './PnlWzemUsr1NSession';
	import PnlWzemUsrMNUsergroup from './PnlWzemUsrMNUsergroup';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzemUsrRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemUsrDetail,
			PnlWzemUsrAAccess,
			PnlWzemUsr1NSession,
			PnlWzemUsrMNUsergroup
			/*
			*/
		},

		mounted() {
			//console.log("PnlWzemUsrRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzemUsrRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzemUsrRec) this.continf = dpcheng.ContInfWzemUsrRec;
				if (dpcheng.StatAppWzemUsrRec) this.statapp = dpcheng.StatAppWzemUsrRec;
				if (dpcheng.StatShrWzemUsrRec) this.statshr = dpcheng.StatShrWzemUsrRec;
				if (dpcheng.TagWzemUsrRec) {
					Wzem.unescapeBlock(dpcheng.TagWzemUsrRec);
					this.tag = dpcheng.TagWzemUsrRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzemUsrDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWzemUsrAAccess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlWzemUsr1NSession.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlWzemUsrMNUsergroup.handleReply(obj);
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
				if (srefIxWzemVDpch == "DpchEngWzemUsrRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzemVDpch == "DpchEngWzemUsrRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWzemVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzemUsrDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWzemUsrAAccess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlWzemUsr1NSession.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlWzemUsrMNUsergroup.handleUpdate(obj);
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
