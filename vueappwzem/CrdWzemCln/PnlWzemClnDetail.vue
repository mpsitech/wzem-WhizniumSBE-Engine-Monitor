<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtJob"
				:label="tag.CptJob"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCal"
				:label="tag.CptCal"
				:disabled="!statshr.TxfCalActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSge"
				:label="tag.CptSge"
				:disabled="!statshr.TxfSgeActive"
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

			<v-select
				class="my-1"
				v-model="contapp.fiFPupTrg"
				return-object
				:items="feedFPupTrg"
				item-value="num"
				item-text="tit1"
				:label="tag.CptTrg"
				v-on:change="handleFiChange('numFPupTrg', contapp.fiFPupTrg)"
				:disabled="!statshr.PupTrgActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupJms"
				return-object
				:items="feedFPupJms"
				item-value="num"
				item-text="tit1"
				:label="tag.CptJms"
				v-on:change="handleFiChange('numFPupJms', contapp.fiFPupJms)"
				:disabled="!statshr.PupJmsActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTjb"
				:label="tag.CptTjb"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fisFLstAms"
				multiple
				return-object
				:items="feedFLstAms"
				item-value="num"
				item-text="tit1"
				:label="tag.CptAms"
				v-on:change="handleFisChange('numsFLstAms', contapp.fisFLstAms)"
				:disabled="!statshr.LstAmsActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfArg"
				:label="tag.CptArg"
				:disabled="!statshr.TxfArgActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupJat"
				return-object
				:items="feedFPupJat"
				item-value="num"
				item-text="tit1"
				:label="tag.CptJat"
				v-on:change="handleFiChange('numFPupJat', contapp.fiFPupJat)"
				:disabled="!statshr.PupJatActive"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzem from '../../scripts/Wzem';
	import vecio from '../../scripts/vecio';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzemClnDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzemClnDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzemClnDetailDo": {
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

			handleFisChange: function(cisref, fis) {
				var nums = new Uint32Array(fis.length);

				for (let i = 0; i < fis.length; i++) nums[i] = fis[i].num;
				this.contiac[cisref] = vecio.toBase64(nums);

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzemClnDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzemClnDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzemClnDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzemClnDetail) this.contiac = dpcheng.ContIacWzemClnDetail;
				if (dpcheng.ContInfWzemClnDetail) this.continf = dpcheng.ContInfWzemClnDetail;
				if (dpcheng.FeedFLstAms) this.feedFLstAms = dpcheng.FeedFLstAms;
				if (dpcheng.FeedFPupJat) this.feedFPupJat = dpcheng.FeedFPupJat;
				if (dpcheng.FeedFPupJms) this.feedFPupJms = dpcheng.FeedFPupJms;
				if (dpcheng.FeedFPupTrg) this.feedFPupTrg = dpcheng.FeedFPupTrg;
				if (dpcheng.StatAppWzemClnDetail) this.statapp = dpcheng.StatAppWzemClnDetail;
				if (dpcheng.StatShrWzemClnDetail) this.statshr = dpcheng.StatShrWzemClnDetail;
				if (dpcheng.TagWzemClnDetail) {
					Wzem.unescapeBlock(dpcheng.TagWzemClnDetail);
					this.tag = dpcheng.TagWzemClnDetail;
				}
				if (dpcheng.ContIacWzemClnDetail) {
					for (let i = 0; i < this.feedFPupTrg.length; i++)
						if (this.feedFPupTrg[i].num == this.contiac.numFPupTrg) {
							this.contapp.fiFPupTrg = this.feedFPupTrg[i];
							break;
						}
					for (let i = 0; i < this.feedFPupJms.length; i++)
						if (this.feedFPupJms[i].num == this.contiac.numFPupJms) {
							this.contapp.fiFPupJms = this.feedFPupJms[i];
							break;
						}
					var fisFLstAms = [];
					var numsFLstAms = vecio.parseUintvec(this.contiac.numsFLstAms);

					for (let i = 0; i < this.feedFLstAms.length; i++)
						if (numsFLstAms.includes(this.feedFLstAms[i].num))
							fisFLstAms.push(this.feedFLstAms[i]);

					this.contapp.fisFLstAms = fisFLstAms;
					for (let i = 0; i < this.feedFPupJat.length; i++)
						if (this.feedFPupJat[i].num == this.contiac.numFPupJat) {
							this.contapp.fiFPupJat = this.feedFPupJat[i];
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
				if (srefIxWzemVDpch == "DpchEngWzemClnDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzemVDpch == "DpchEngWzemClnDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstAms: null,

			feedFPupJat: null,

			feedFPupJms: null,

			feedFPupTrg: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTrg: null,

				fiFPupJms: null,

				fisFLstAms: [],

				fiFPupJat: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
