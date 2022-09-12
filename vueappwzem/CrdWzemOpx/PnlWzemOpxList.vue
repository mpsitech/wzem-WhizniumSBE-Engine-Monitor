<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>
						<span>{{tag.Cpt}}</span>
						<span class="caption">{{TxtFor}}</span>
						<span>{{continf.TxtPre}}</span>
						<span>{{Cpt2}}</span>
					</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;
					<v-btn
						v-if="statshr.srefIxWzemVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClipboardClick()"
						:value="1"
					>
						<v-icon color="white">mdi-clipboard</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statshr.srefIxWzemVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButNewClick')"
						:value="1"
					>
						<v-icon color="white">mdi-file-plus</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzemVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDeleteClick')"
						:value="1"
						:disabled="!statshr.ButDeleteActive"
					>
						<v-icon color="white">mdi-file-remove</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzemVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButFilterClick')"
						:value="1"
					>
						<v-icon color="white">{{contapp.ButFilterOn ? 'mdi-filter' : 'mdi-filter-off'}}</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWzemVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWzemVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWzemVExpstate=='regd'"
		>
			<v-data-table
				:headers="headers"
				:items="contapp.rows"
				:items-per-page="10"
				item-key="jnum"
				single-select
				show-select
				class="elevation-1 my-3"
				v-on:item-selected="handleSelect"
			/>

			<v-row>
				<v-col align="end">
					<v-tooltip left>
						<template v-slot:activator="{on,attrs}">
							<v-btn
								fab
								small
								light
								v-bind="attrs"
								v-on="on"
								:color="fiFCsiQst.sref == 'ong' ? 'orange' : fiFCsiQst.sref == 'red' ? 'red' : fiFCsiQst.sref == 'yel' ? 'yellow' : fiFCsiQst.sref == 'grn' ? 'green' : 'primary'"
								v-on:click="handleButClick('ButRefreshClick')"
							>
								<v-icon color="white">mdi-refresh</v-icon>
							</v-btn>
						</template>
						{{fiFCsiQst.tit1}}
					</v-tooltip>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzemOpxList',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzemOpxList.mounted() with scrJref = " + this.scrJref);

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

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWzemOpxListDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButClipboardClick: function() {
				/*
				*/
				Wzem.copyToClipboard(document, this.continf, this.rst, this.statshrqry, this.tag,
							["Job","Xor","Sta","Sto"],
							["job","xor","sta","sto"]);
				/*
				*/
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppWzemOpxListData": {
						"scrJref": this.scrJref,
						"StgIacQryWzemOpxList": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzemOpxList"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzemOpxListData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzemOpxListData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzemOpxList) this.contiac = dpcheng.ContIacWzemOpxList;
				if (dpcheng.ContInfWzemOpxList) this.continf = dpcheng.ContInfWzemOpxList;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.FeedFTos) this.feedFTos = dpcheng.FeedFTos;
				if (dpcheng.StatShrWzemOpxList) this.statshr = dpcheng.StatShrWzemOpxList;
				if (dpcheng.StgIacWzemOpxList) this.stgiac = dpcheng.StgIacWzemOpxList;
				if (dpcheng.TagWzemOpxList) {
					Wzem.unescapeBlock(dpcheng.TagWzemOpxList);
					this.tag = dpcheng.TagWzemOpxList;
				}
				if (dpcheng.ListWzemQOpxList) this.rst = dpcheng.ListWzemQOpxList;
				if (dpcheng.StatAppQryWzemOpxList) this.statappqry = dpcheng.StatAppQryWzemOpxList;
				if (dpcheng.StatShrQryWzemOpxList) this.statshrqry = dpcheng.StatShrQryWzemOpxList;
				if (dpcheng.StgIacQryWzemOpxList) this.stgiacqry = dpcheng.StgIacQryWzemOpxList;
				if (dpcheng.ContInfWzemOpxList) {
					if (!this.continf.ButFilterOn) this.contapp.ButFilterOn = 0;
					else this.contapp.ButFilterOn = 1;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagWzemOpxList) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoJob", text: this.tag.TcoJob}, {value: "TcoXor", text: this.tag.TcoXor}, {value: "TcoSta", text: this.tag.TcoSta}, {value: "TcoSto", text: this.tag.TcoSto});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWzemQOpxList) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoJob: rec["job"], TcoXor: rec["xor"], TcoSta: rec["sta"], TcoSto: rec["sto"]})
						/*
						*/

					}

					this.contapp.rows = rows;
				}
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
				if (srefIxWzemVDpch == "DpchEngWzemOpxListData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzemVDpch == "DpchEngWzemOpxListData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			/*
			*/
			Cpt2: function() {
				if (this.statshr.srefIxWzemVExpstate == "mind") return(" (" + this.statshrqry.ntot + ")");
				return "";
			},

			TxtFor: function() {
				return(" " + Wzem.strFor(this.tag.TxtFor, this.continf.TxtFor) + " ");
			},
			/*
			*/
			/*
			*/

			headers: function() {
				return this.contapp.tcos.filter(x => x.value != "jnum")
			},

			fiFCsiQst: function() {
				if (this.feedFCsiQst && this.continf)
					for (var i = 0; i < this.feedFCsiQst.length; i++)
						if (this.feedFCsiQst[i].num == this.continf.numFCsiQst) return this.feedFCsiQst[i];

				return {sref: "gry", tit1: "invalid"}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFCsiQst: null,

			feedFTos: null,

			statshr: null,

			stgiac: null,

			tag: null,

			rst: null,

			statappqry: null,

			statshrqry: null,

			stgiacqry: null,

			contapp: {
				ButFilterOn: 0,

				tcos: [],
				rows: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
