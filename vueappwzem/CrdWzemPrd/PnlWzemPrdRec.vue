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
					<PnlWzemPrdDetail
						v-on:request="handleRequest"
						ref="PnlWzemPrdDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWzemPrd1NEvent
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemPrd1NEvent"
						:scrJref=statshr.scrJref1NEvent
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWzemPrd1NNode
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemPrd1NNode"
						:scrJref=statshr.scrJref1NNode
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWzemPrd1NJob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemPrd1NJob"
						:scrJref=statshr.scrJref1NJob
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
	import PnlWzemPrdDetail from './PnlWzemPrdDetail';
	import PnlWzemPrd1NEvent from './PnlWzemPrd1NEvent';
	import PnlWzemPrd1NNode from './PnlWzemPrd1NNode';
	import PnlWzemPrd1NJob from './PnlWzemPrd1NJob';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzemPrdRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemPrdDetail,
			PnlWzemPrd1NEvent,
			PnlWzemPrd1NNode,
			PnlWzemPrd1NJob
			/*
			*/
		},

		mounted() {
			//console.log("PnlWzemPrdRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzemPrdRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzemPrdRec) this.continf = dpcheng.ContInfWzemPrdRec;
				if (dpcheng.StatAppWzemPrdRec) this.statapp = dpcheng.StatAppWzemPrdRec;
				if (dpcheng.StatShrWzemPrdRec) this.statshr = dpcheng.StatShrWzemPrdRec;
				if (dpcheng.TagWzemPrdRec) {
					Wzem.unescapeBlock(dpcheng.TagWzemPrdRec);
					this.tag = dpcheng.TagWzemPrdRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzemPrdDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NEvent) this.$refs.PnlWzemPrd1NEvent.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NNode) this.$refs.PnlWzemPrd1NNode.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NJob) this.$refs.PnlWzemPrd1NJob.handleReply(obj);
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
				if (srefIxWzemVDpch == "DpchEngWzemPrdRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzemVDpch == "DpchEngWzemPrdRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWzemVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzemPrdDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NEvent) this.$refs.PnlWzemPrd1NEvent.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NNode) this.$refs.PnlWzemPrd1NNode.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NJob) this.$refs.PnlWzemPrd1NJob.handleUpdate(obj);
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
