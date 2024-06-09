<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-select
				class="my-1"
				v-model="contapp.fiFPupTyp"
				return-object
				:items="feedFPupTyp"
				item-value="num"
				item-text="tit1"
				:label="tag.CptTyp"
				v-on:change="handleFiChange('numFPupTyp', contapp.fiFPupTyp)"
				:disabled="!statshr.PupTypActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPrd"
				:label="tag.CptPrd"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSta"
				:label="tag.CptSta"
				:disabled="!statshr.TxfStaActive"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFLstClu"
				return-object
				:items="feedFLstClu"
				item-value="num"
				item-text="tit1"
				:label="tag.CptClu"
				v-on:change="handleFiChange('numFLstClu', contapp.fiFLstClu)"
				:disabled="!statshr.LstCluActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtCal"
				:label="tag.CptCal"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtCln"
				:label="tag.CptCln"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtJob"
				:label="tag.CptJob"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtNde"
				:label="tag.CptNde"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtOpx"
				:label="tag.CptOpx"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPst"
				:label="tag.CptPst"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmd"
				:label="tag.CptCmd"
				:disabled="!statshr.TxfCmdActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfFnm"
				:label="tag.CptFnm"
				:disabled="!statshr.TxfFnmActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfFeg"
				:label="tag.CptFeg"
				:disabled="!statshr.TxfFegActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfMtd"
				:label="tag.CptMtd"
				:disabled="!statshr.TxfMtdActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfXsr"
				:label="tag.CptXsr"
				:disabled="!statshr.TxfXsrActive"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgDch}}
			</h3>

			<v-text-field
				v-if="statshr.TxfDchDchAvail"
				class="my-1"
				v-model="contiac.TxfDchDch"
				:label="tag.CptDchDch"
				:disabled="!statshr.TxfDchDchActive"
			/>

			<v-text-field
				v-if="statshr.TxfDchMskAvail"
				class="my-1"
				v-model="contiac.TxfDchMsk"
				:label="tag.CptDchMsk"
				:disabled="!statshr.TxfDchMskActive"
			/>

			<v-text-field
				v-if="statshr.TxfDchCntAvail"
				class="my-1"
				v-model="contiac.TxfDchCnt"
				:label="tag.CptDchCnt"
				:disabled="!statshr.TxfDchCntActive"
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
		name: 'PnlWzemEvtDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzemEvtDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzemEvtDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleFiChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzemEvtDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzemEvtDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzemEvtDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzemEvtDetail) this.contiac = dpcheng.ContIacWzemEvtDetail;
				if (dpcheng.ContInfWzemEvtDetail) this.continf = dpcheng.ContInfWzemEvtDetail;
				if (dpcheng.FeedFLstClu) this.feedFLstClu = dpcheng.FeedFLstClu;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWzemEvtDetail) this.statapp = dpcheng.StatAppWzemEvtDetail;
				if (dpcheng.StatShrWzemEvtDetail) this.statshr = dpcheng.StatShrWzemEvtDetail;
				if (dpcheng.TagWzemEvtDetail) {
					Wzem.unescapeBlock(dpcheng.TagWzemEvtDetail);
					this.tag = dpcheng.TagWzemEvtDetail;
				}
				if (dpcheng.ContIacWzemEvtDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFLstClu.length; i++)
						if (this.feedFLstClu[i].num == this.contiac.numFLstClu) {
							this.contapp.fiFLstClu = this.feedFLstClu[i];
							break;
						}
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
				if (srefIxWzemVDpch == "DpchEngWzemEvtDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzemVDpch == "DpchEngWzemEvtDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstClu: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFLstClu: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
