<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
				:disabled="!statshr.TxfTitActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfFnm"
				:label="tag.CptFnm"
				:disabled="!statshr.TxfFnmActive"
			/>

			<div
				class="my-1"
			>
				<!-- IP divJ - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtLnm"
				:label="tag.CptLnm"
			/>

			<v-divider/>

			<div
				class="my-1"
			>
				<!-- IP divDrv - INSERT -->
			</div>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSex"
				:items="feedFPupSex"
				:label='tag.CptSex'
				v-on:change="handlePupChange('numFPupSex', contapp.fiFPupSex)"
				:disabled="!statshr.PupSexActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTel"
				:label="tag.CptTel"
				:disabled="!statshr.TxfTelActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfEml"
				:label="tag.CptEml"
				:disabled="!statshr.TxfEmlActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSal"
				:label="tag.CptSal"
				:disabled="!statshr.TxfSalActive"
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
		name: 'PnlWzemPrsDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzemPrsDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWzemPrsDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzemPrsDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzemPrsDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzemPrsDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzemPrsDetail) this.contiac = dpcheng.ContIacWzemPrsDetail;
				if (dpcheng.ContInfWzemPrsDetail) this.continf = dpcheng.ContInfWzemPrsDetail;
				if (dpcheng.FeedFLstDrv) this.feedFLstDrv = dpcheng.FeedFLstDrv;
				if (dpcheng.FeedFPupJ) this.feedFPupJ = dpcheng.FeedFPupJ;
				if (dpcheng.FeedFPupSex) this.feedFPupSex = dpcheng.FeedFPupSex;
				if (dpcheng.StatAppWzemPrsDetail) this.statapp = dpcheng.StatAppWzemPrsDetail;
				if (dpcheng.StatShrWzemPrsDetail) this.statshr = dpcheng.StatShrWzemPrsDetail;
				if (dpcheng.TagWzemPrsDetail) {
					Wzem.unescapeBlock(dpcheng.TagWzemPrsDetail);
					this.tag = dpcheng.TagWzemPrsDetail;
				}
				if (dpcheng.ContIacWzemPrsDetail) {
					for (let i = 0; i < this.feedFPupJ.length; i++)
						if (this.feedFPupJ[i].num == this.contiac.numFPupJ) {
							this.contapp.fiFPupJ = this.feedFPupJ[i];
							break;
						}
					for (let i = 0; i < this.feedFPupSex.length; i++)
						if (this.feedFPupSex[i].num == this.contiac.numFPupSex) {
							this.contapp.fiFPupSex = this.feedFPupSex[i];
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
				if (srefIxWzemVDpch == "DpchEngWzemPrsDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzemVDpch == "DpchEngWzemPrsDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstDrv: null,

			feedFPupJ: null,

			feedFPupSex: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJ: null,

				fisFLstDrv: [],

				fiFPupSex: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
