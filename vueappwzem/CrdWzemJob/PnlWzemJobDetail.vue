<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPrd"
				:label="tag.CptPrd"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfJob"
				:label="tag.CptJob"
				:disabled="!statshr.TxfJobActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfXjr"
				:label="tag.CptXjr"
				:disabled="!statshr.TxfXjrActive"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSta"
				:label="tag.CptSta"
				:disabled="!statshr.TxfStaActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSto"
				:label="tag.CptSto"
				:disabled="!statshr.TxfStoActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSup"
				:label="tag.CptSup"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkCls"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptCls"
				:disabled="!statshr.ChkClsActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkSnc"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptSnc"
				:disabled="!statshr.ChkSncActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkDcl"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptDcl"
				:disabled="!statshr.ChkDclActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkStm"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptStm"
				:disabled="!statshr.ChkStmActive"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzemJobDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzemJobDetail.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzemInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzemJobDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzemJobDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzemJobDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzemJobDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzemJobDetail) this.contiac = dpcheng.ContIacWzemJobDetail;
				if (dpcheng.ContInfWzemJobDetail) this.continf = dpcheng.ContInfWzemJobDetail;
				if (dpcheng.StatAppWzemJobDetail) this.statapp = dpcheng.StatAppWzemJobDetail;
				if (dpcheng.StatShrWzemJobDetail) this.statshr = dpcheng.StatShrWzemJobDetail;
				if (dpcheng.TagWzemJobDetail) {
					Wzem.unescapeBlock(dpcheng.TagWzemJobDetail);
					this.tag = dpcheng.TagWzemJobDetail;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzemVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzemVDpch, dpcheng) {
				if (srefIxWzemVDpch == "DpchEngWzemJobDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzemVDpch == "DpchEngWzemJobDetailData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

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
