<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSrf"
				:label="tag.CptSrf"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmt"
				:label="tag.CptCmt"
				:disabled="!statshr.TxfCmtActive"
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
		name: 'PnlWzemUsgDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzemUsgDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzemUsgDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzemUsgDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzemUsgDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzemUsgDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzemUsgDetail) this.contiac = dpcheng.ContIacWzemUsgDetail;
				if (dpcheng.ContInfWzemUsgDetail) this.continf = dpcheng.ContInfWzemUsgDetail;
				if (dpcheng.StatAppWzemUsgDetail) this.statapp = dpcheng.StatAppWzemUsgDetail;
				if (dpcheng.StatShrWzemUsgDetail) this.statshr = dpcheng.StatShrWzemUsgDetail;
				if (dpcheng.TagWzemUsgDetail) {
					Wzem.unescapeBlock(dpcheng.TagWzemUsgDetail);
					this.tag = dpcheng.TagWzemUsgDetail;
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
				if (srefIxWzemVDpch == "DpchEngWzemUsgDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzemVDpch == "DpchEngWzemUsgDetailData") this.mergeDpchEngData(obj.dpcheng);
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
