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
				v-model="contiac.TxfXnr"
				:label="tag.CptXnr"
				:disabled="!statshr.TxfXnrActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfIp"
				:label="tag.CptIp"
				:disabled="!statshr.TxfIpActive"
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
				v-model="contiac.TxfPrt"
				:label="tag.CptPrt"
				:disabled="!statshr.TxfPrtActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfOrn"
				:label="tag.CptOrn"
				:disabled="!statshr.TxfOrnActive"
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
		name: 'PnlWzemNdeDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzemNdeDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzemNdeDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzemNdeDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzemNdeDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzemNdeDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzemNdeDetail) this.contiac = dpcheng.ContIacWzemNdeDetail;
				if (dpcheng.ContInfWzemNdeDetail) this.continf = dpcheng.ContInfWzemNdeDetail;
				if (dpcheng.StatAppWzemNdeDetail) this.statapp = dpcheng.StatAppWzemNdeDetail;
				if (dpcheng.StatShrWzemNdeDetail) this.statshr = dpcheng.StatShrWzemNdeDetail;
				if (dpcheng.TagWzemNdeDetail) {
					Wzem.unescapeBlock(dpcheng.TagWzemNdeDetail);
					this.tag = dpcheng.TagWzemNdeDetail;
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
				if (srefIxWzemVDpch == "DpchEngWzemNdeDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzemVDpch == "DpchEngWzemNdeDetailData") this.mergeDpchEngData(obj.dpcheng);
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
