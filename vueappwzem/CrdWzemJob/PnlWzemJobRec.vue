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
					<PnlWzemJobDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemJobDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWzemJob1NClstn
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemJob1NClstn"
						:scrJref=statshr.scrJref1NClstn
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWzemJob1NPreset
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemJob1NPreset"
						:scrJref=statshr.scrJref1NPreset
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWzemJob1NCall
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemJob1NCall"
						:scrJref=statshr.scrJref1NCall
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWzemJob1NOp
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemJob1NOp"
						:scrJref=statshr.scrJref1NOp
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWzemJobSup1NJob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWzemJobSup1NJob"
						:scrJref=statshr.scrJrefSup1NJob
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
	import PnlWzemJobDetail from './PnlWzemJobDetail';
	import PnlWzemJob1NClstn from './PnlWzemJob1NClstn';
	import PnlWzemJob1NPreset from './PnlWzemJob1NPreset';
	import PnlWzemJob1NCall from './PnlWzemJob1NCall';
	import PnlWzemJob1NOp from './PnlWzemJob1NOp';
	import PnlWzemJobSup1NJob from './PnlWzemJobSup1NJob';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzemJobRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemJobDetail,
			PnlWzemJob1NClstn,
			PnlWzemJob1NPreset,
			PnlWzemJob1NCall,
			PnlWzemJob1NOp,
			PnlWzemJobSup1NJob
			/*
			*/
		},

		mounted() {
			//console.log("PnlWzemJobRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzemJobRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWzemJobRec) this.continf = dpcheng.ContInfWzemJobRec;
				if (dpcheng.StatAppWzemJobRec) this.statapp = dpcheng.StatAppWzemJobRec;
				if (dpcheng.StatShrWzemJobRec) this.statshr = dpcheng.StatShrWzemJobRec;
				if (dpcheng.TagWzemJobRec) {
					Wzem.unescapeBlock(dpcheng.TagWzemJobRec);
					this.tag = dpcheng.TagWzemJobRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzemJobDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NClstn) this.$refs.PnlWzemJob1NClstn.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NPreset) this.$refs.PnlWzemJob1NPreset.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NCall) this.$refs.PnlWzemJob1NCall.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NOp) this.$refs.PnlWzemJob1NOp.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NJob) this.$refs.PnlWzemJobSup1NJob.handleReply(obj);
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
				if (srefIxWzemVDpch == "DpchEngWzemJobRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzemVDpch == "DpchEngWzemJobRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWzemVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWzemJobDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NClstn) this.$refs.PnlWzemJob1NClstn.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NPreset) this.$refs.PnlWzemJob1NPreset.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NCall) this.$refs.PnlWzemJob1NCall.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NOp) this.$refs.PnlWzemJob1NOp.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NJob) this.$refs.PnlWzemJobSup1NJob.handleUpdate(obj);
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
