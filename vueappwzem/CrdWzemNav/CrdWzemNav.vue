<template>
	<div v-if="initdonePnls">
		<div class="d-flex pa-2 align-center">
			<img src="../../assets/logo.png" height="56" alt="logo" class="mr-1">
			<div>
				<div class="title font-weight-bold text-uppercase primary--text mx-2">{{CptTitle}}</div>
				<div class="caption grey--text mx-2">{{CptVersion}}</div>
			</div>
		</div>

		<v-divider/>

		<v-list>
			<v-list-item-group v-model="MenApp">
				<v-list-item
					active-class="primary--text"
					v-on:click="handleMitClick('MitAppAbtClick')"
					value="MitAppAbt"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitAppAbt}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-list-item
					v-if="statshr.MitAppLoiAvail"
					active-class="primary--text"
					v-on:click="handleMitClick('MitAppLoiClick')"
					value="MitAppLoi"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitAppLoi}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>
			</v-list-item-group>

			<v-divider/>

			<v-list-item-group>
				<v-list-item
					v-if="statshr.MitSesSpsAvail"
					active-class="primary--text"
					v-on:click="handleMitClick('MitSesSpsClick')"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitSesSps}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-list-item
					active-class="primary--text"
					v-on:click="handleMitClick('MitSesTrmClick')"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitSesTrm}}</v-list-item-title>
					</v-list-item-content>
					<v-tooltip right>
						<template v-slot:activator="{on,attrs}">
							<v-list-item-icon>
								<v-icon v-bind="attrs" v-on="on">mdi-information-outline</v-icon>
							</v-list-item-icon>
						</template>
						{{continf.MtxSesSes1 + " " + continf.MtxSesSes2 + " " + continf.MtxSesSes3}}
					</v-tooltip>
				</v-list-item>
			</v-list-item-group>

			<v-divider/>

			<v-list-item-group v-if="statshr.pnlpreAvail">
				<v-list-item
					v-for="(short, j) in mitsPre"
					:key="j"
					active-class="red--text"
					class="red--text"
				>
					<v-list-item-content>
						<v-list-item-subtitle class="red--text text--lighten-3 overline">{{pnlpre.tag['Cpt' + short]}}</v-list-item-subtitle>
						<v-list-item-title>{{pnlpre.continf['Txt' + short]}}</v-list-item-title>
					</v-list-item-content>
					<v-list-item-icon>
						<v-icon
							color="red"
							v-on:click="handleButClick_other('Pre', statshr.scrJrefPre, 'But' + short + 'RemoveClick')"
						>
							mdi-close-circle-outline
						</v-icon>
					</v-list-item-icon>
				</v-list-item>
			</v-list-item-group>

			<v-divider v-if="statshr.pnlpreAvail"/>

			<v-list-item-group v-for="({sref, mits}, i) in MbarContent" :key="i" v-model="MbarContent[i].mit">
				<v-list-item small disabled dense class="grey lighten-5">
					<v-list-item-content :style="{'text-align':'right'}">
						<v-list-item-title class="grey--text text--darken-4 overline">{{MenContentHdg(sref)}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-divider/>

				<v-list-item
					v-for="(sref, j) in mitsContent(mits)"
					:key="j"
					active-class="grey lighten-5"
					class="grey lighten-5"
					v-on:click="handleMitContentClick(sref + 'Click')"
					:value="sref"
					:disabled="!MitContentActive(sref)"
				>
					<v-list-item-content>
						<v-list-item-title>{{MitContent(sref)}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-divider/>
			</v-list-item-group>

			<v-list-item small disabled dense>
				<v-list-item-content :style="{'text-align':'right'}">
					<v-list-item-title class="overline">{{pnlheadbar.tag.MenCrd}}</v-list-item-title>
				</v-list-item-content>
			</v-list-item>

			<v-divider/>

			<v-list-item-group mandatory>
				<v-list-group v-for="({pnlsref, mits}, i) in MenCrd" :key="i">
					<template v-slot:activator>
						<v-list-item-content>
							<v-list-item-title>{{MenCrdHdg(pnlsref)}}</v-list-item-title>
						</v-list-item-content>
					</template>

					<v-list-item
						v-for="(sref, j) in mitsCrd(mits)"
						:key="j"
						active-class="primary--text"
						v-on:click="handleMitCrdopenClick(sref + 'Click')"
						:value="sref"
						:disabled="!MitCrdActive(sref)"
					>
						<v-tooltip right>
							<template v-slot:activator="{on,attrs}">
								<v-list-item-content v-bind="attrs" v-on="on">
									<v-list-item-title>{{MitCrd(sref)}}</v-list-item-title>
								</v-list-item-content>
							</template><span v-html="LstHist(pnlsref, sref.substring(3 + 3))"/>
						</v-tooltip>
					</v-list-item>
				</v-list-group>

				<v-divider/>
			</v-list-item-group>
		</v-list>
	</div>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzemNav',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("CrdWzemNav.mounted() with scrJref = " + this.scrJref);

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

			handleMitClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWzemNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"});
			},

			handleMitCrdopenClick: function(ctlsref) {
				if (this.content.sref.substring(3 + 4) == ctlsref.substring(3 + 3, 3 + 3 + 3)) return;

				const dpchapp = {
					"DpchAppWzemNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppCrdopenReply"});
			},

			handleButClick_other: function(sref, scrJref, ctlsref) {
				const dpchapp = {
					["DpchAppWzemNav" + sref + "Do"]: {
						"scrJref": scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"});
			},

			handleMitContentClick: function(ctlsref) {
				const dpchapp = {
					["DpchApp" + this.content.sref.substring(3) + "Do"]: {
						"scrJref": this.content.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.content.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"}); // reply ends up in content card
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfWzemNav) this.continf = dpcheng.ContInfWzemNav;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzemNav) this.statapp = dpcheng.StatAppWzemNav;
				if (dpcheng.StatShrWzemNav) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrWzemNav.scrJrefDlgloaini != "");
						dlgclose = (this.statshr.scrJrefDlgloaini != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWzemNav.scrJrefDlgloaini != "") {
								srefDlg = "DlgWzemNavLoaini";
								scrJrefDlg = dpcheng.StatShrWzemNav.scrJrefDlgloaini;
							}
						}
					}
					this.statshr = dpcheng.StatShrWzemNav;
				}
				if (dpcheng.TagWzemNav) {
					Wzem.unescapeBlock(dpcheng.TagWzemNav);
					this.tag = dpcheng.TagWzemNav;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
				/*
				*/
			},

			/*
			*/
			mergeDpchEngData_pnlheadbar: function(dpcheng) {
				if (dpcheng.StatShrWzemNavHeadbar) this.pnlheadbar.statshr = dpcheng.StatShrWzemNavHeadbar;
				if (dpcheng.StgInfWzemNavHeadbar) this.pnlheadbar.stginf = dpcheng.StgInfWzemNavHeadbar;
				if (dpcheng.TagWzemNavHeadbar) {
					Wzem.unescapeBlock(dpcheng.TagWzemNavHeadbar);
					this.pnlheadbar.tag = dpcheng.TagWzemNavHeadbar;
				}
			},

			mergeDpchEngData_pnlpre: function(dpcheng) {
				if (dpcheng.ContInfWzemNavPre) this.pnlpre.continf = dpcheng.ContInfWzemNavPre;
				if (dpcheng.StatShrWzemNavPre) this.pnlpre.statshr = dpcheng.StatShrWzemNavPre;
				if (dpcheng.TagWzemNavPre) {
					Wzem.unescapeBlock(dpcheng.TagWzemNavPre);
					this.pnlpre.tag = dpcheng.TagWzemNavPre;
				}
			},

			mergeDpchEngData_pnladmin: function(dpcheng) {
				if (dpcheng.ContIacWzemNavAdmin) this.pnladmin.contiac = dpcheng.ContIacWzemNavAdmin;
				if (dpcheng.FeedFLstPrs) this.pnladmin.feedFLstPrs = dpcheng.FeedFLstPrs;
				if (dpcheng.FeedFLstUsg) this.pnladmin.feedFLstUsg = dpcheng.FeedFLstUsg;
				if (dpcheng.FeedFLstUsr) this.pnladmin.feedFLstUsr = dpcheng.FeedFLstUsr;
				if (dpcheng.StatAppWzemNavAdmin) this.pnladmin.statapp = dpcheng.StatAppWzemNavAdmin;
				if (dpcheng.StatShrWzemNavAdmin) this.pnladmin.statshr = dpcheng.StatShrWzemNavAdmin;
				if (dpcheng.TagWzemNavAdmin) {
					Wzem.unescapeBlock(dpcheng.TagWzemNavAdmin);
					this.pnladmin.tag = dpcheng.TagWzemNavAdmin;
				}
			},

			mergeDpchEngData_pnlmon: function(dpcheng) {
				if (dpcheng.ContIacWzemNavMon) this.pnlmon.contiac = dpcheng.ContIacWzemNavMon;
				if (dpcheng.FeedFLstCal) this.pnlmon.feedFLstCal = dpcheng.FeedFLstCal;
				if (dpcheng.FeedFLstCln) this.pnlmon.feedFLstCln = dpcheng.FeedFLstCln;
				if (dpcheng.FeedFLstEvt) this.pnlmon.feedFLstEvt = dpcheng.FeedFLstEvt;
				if (dpcheng.FeedFLstJob) this.pnlmon.feedFLstJob = dpcheng.FeedFLstJob;
				if (dpcheng.FeedFLstNde) this.pnlmon.feedFLstNde = dpcheng.FeedFLstNde;
				if (dpcheng.FeedFLstOpx) this.pnlmon.feedFLstOpx = dpcheng.FeedFLstOpx;
				if (dpcheng.FeedFLstPrd) this.pnlmon.feedFLstPrd = dpcheng.FeedFLstPrd;
				if (dpcheng.FeedFLstPst) this.pnlmon.feedFLstPst = dpcheng.FeedFLstPst;
				if (dpcheng.StatAppWzemNavMon) this.pnlmon.statapp = dpcheng.StatAppWzemNavMon;
				if (dpcheng.StatShrWzemNavMon) this.pnlmon.statshr = dpcheng.StatShrWzemNavMon;
				if (dpcheng.TagWzemNavMon) {
					Wzem.unescapeBlock(dpcheng.TagWzemNavMon);
					this.pnlmon.tag = dpcheng.TagWzemNavMon;
				}
			},

			/*
			*/

			mergeDpchEngData_content: function(dpcheng) {
				if (dpcheng["StatShr" + this.content.sref.substring(3)]) this.content.statshr = dpcheng["StatShr" + this.content.sref.substring(3)];
				if (dpcheng["Tag" + this.content.sref.substring(3)]) {
					Wzem.unescapeBlock(dpcheng["Tag" + this.content.sref.substring(3)]);
					this.content.tag = dpcheng["Tag" + this.content.sref.substring(3)];
				}

				this.$forceUpdate();
			},

			mergeDpchEngData_contentpnlheadbar: function(dpcheng) {
				if (dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"]) {
					Wzem.unescapeBlock(dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"]);
					this.content.pnlheadbar.tag = dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"];
				}

				this.MbarContent = this["Mbar" + this.content.sref.substring(3 + 4)]
			},

			handleCrdopen: function(obj) {
				//console.log(obj.srefCrd);
				this.MenNav = "MitCrd" + obj.srefCrd.substring(3 + 4);

				this.content.sref = obj.srefCrd;
				this.content.scrJref = obj.scrJrefCrd;

				this.content.statshr = {};
				this.content.tag = {};

				this.content.initdone = false;
				this.content.pnlheadbar.initdone = false;

				this.initOther(this.content.scrJref);

				// obj content {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false}
			},

			handleAlrdlgclose: function() {
				this.MenApp = 0;
				for (var men in this.MbarContent) this.MbarContent[men].mit = 0
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppCrdopenReply") this.handleDpchAppCrdopenReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDoReply") this.handleDpchAppDoReply(obj.srefIxWzemVDpch, obj.dpcheng);
			},

			handleUpdate: function(obj) {
				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzemVDpch == "DpchEngWzemNavData") this.mergeDpchEngData(obj.dpcheng);

				} else if (this.initdonePnls) {
					if (obj.dpcheng.scrJref == this.statshr.scrJrefAdmin) this.mergeDpchEngData_pnladmin(obj.dpcheng);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefMon) this.mergeDpchEngData_pnlmon(obj.dpcheng);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefPre) this.mergeDpchEngData_pnlpre(obj.dpcheng);

					if (this.content.initdone) if (obj.dpcheng.scrJref == this.content.scrJref) this.mergeDpchEngData_content(obj.dpcheng);
				}
			},

			initOther: function(scrJref) {
				const dpchapp = {
					"DpchAppWzemInit": {
						"scrJref": scrJref
					}
				};

				this.$emit("request", {scrJref: scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
			},

			handleDpchAppInitReply: function(dpcheng) {
				if (dpcheng.scrJref == this.scrJref) {
					this.mergeDpchEngData(dpcheng);
					this.initdone = true;
				}

				if (this.initdone) {
					/*
					*/
					if (dpcheng.scrJref == this.statshr.scrJrefHeadbar) {
						this.mergeDpchEngData_pnlheadbar(dpcheng);
						this.statapp.initdoneHeadbar = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefPre) {
						this.mergeDpchEngData_pnlpre(dpcheng);
						this.statapp.initdonePre = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefAdmin) {
						this.mergeDpchEngData_pnladmin(dpcheng);
						this.statapp.initdoneAdmin = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefMon) {
						this.mergeDpchEngData_pnlmon(dpcheng);
						this.statapp.initdoneMon = true;
					} else if (dpcheng.scrJref == this.content.scrJref) {
						this.mergeDpchEngData_content(dpcheng);
						this.content.initdone = true;
					}

					if (!this.statapp.initdoneHeadbar) this.initOther(this.statshr.scrJrefHeadbar);
					else if (!this.statapp.initdonePre) this.initOther(this.statshr.scrJrefPre);
					else if (!this.statapp.initdoneAdmin) this.initOther(this.statshr.scrJrefAdmin);
					else if (!this.statapp.initdoneMon) this.initOther(this.statshr.scrJrefMon);
					/*
					*/
					else this.initdonePnls = true;

					if (this.content.initdone) {
						if (dpcheng.scrJref == this.content.statshr.scrJrefHeadbar) {
							this.mergeDpchEngData_contentpnlheadbar(dpcheng);
							this.content.pnlheadbar.initdone = true;
						}
		
						if (!this.content.pnlheadbar.initdone) this.initOther(this.content.statshr.scrJrefHeadbar);
					}
				}
			},

			handleDpchAppDoReply: function(srefIxWzemVDpch, dpcheng) {
				if (srefIxWzemVDpch == "DpchEngWzemNavData") this.mergeDpchEngData(dpcheng);
				else if (srefIxWzemVDpch == "DpchEngWzemNavPreData") this.mergeDpchEngData_pnlpre(dpcheng);
			},

			handleDpchAppCrdopenReply: function(dpcheng) {
				if (dpcheng.accepted) {
					//console.log("CrdWzemNav.handleDpchAppCrdopenReply() accepted");

					this.$emit("crdopen", {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false});

				} else {
					//console.log("CrdWzemNav.handleDpchAppCrdopenReply() denied");
				}
			},

			// (static) CrdNav.MenApp: tag

			// (static) CrdNav.MenSes: tag, continf (pop-up)

			// (dynamic) CrdNav.MenCrd: pnl*.tag (module), crd.tag (mit). pnl*.continf (history)
			MenCrdHdg: function(pnlsref) {
				if (this[pnlsref] == null) return pnlsref;
				return this[pnlsref].tag.Cpt;
			},

			mitsCrd: function(mitsAll) {
				var mits = [];

				for (const ctlsref of mitsAll) {
					if (this.statshr[ctlsref + "Avail"] != null) if (this.statshr[ctlsref + "Avail"] == false) continue;
					mits.push(ctlsref);
				}
					
				return mits
			},

			MitCrd: function(ctlsref) {
				if (this.tag[ctlsref] == null) return ctlsref;
				return this.tag[ctlsref]
			},

			MitCrdActive: function(ctlsref) {
				if (this.statshr[ctlsref + "Active"] == null) return true;
				return this.statshr[ctlsref + "Active"]
			},

			// (dynamic) PnlNavPre: tag, continf

			// (dynamic) content.Mbar: pnlheadbar.tag (men), crd.tag (mit)
			MenContentHdg: function(ctlsref) {
				if (this.content.pnlheadbar.tag == null) return ctlsref;
				if (this.content.pnlheadbar.tag[ctlsref] == null) return ctlsref;
				return this.content.pnlheadbar.tag[ctlsref];
			},

			mitsContent: function(mitsAll) {
				var mits = [];

				for (const ctlsref of mitsAll) {
					if (this.content.statshr[ctlsref + "Avail"] != null) if (this.content.statshr[ctlsref + "Avail"] == false) continue;
					mits.push(ctlsref);
				}

				return mits
			},

			MitContent: function(ctlsref) {
				if (this.content.tag == null) return ctlsref;
				if (this.content.tag[ctlsref] == null) return ctlsref;
				return this.content.tag[ctlsref];
			},

			MitContentActive: function(ctlsref) {
				if (this.content.statshr == null) return true;
				if (this.content.statshr[ctlsref + "Active"] == null) return true;
				return this.content.statshr[ctlsref + "Active"]
			},

			LstHist: function(pnlsref, short) {
				var retval = "";
				const feed = this[pnlsref]["feedFLst" + short];

				if (feed != null)
					for (var i = 0; i < feed.length; i++) {
						var fi = feed[i];
						retval += "<p class='mb-0'>" + fi.tit1 + "</p>";
					}

				return retval;
			}
		},

		computed: {
			CptTitle: function() {
				return Wzem.title;
			},

			CptVersion: function() {
				return("v" + Wzem.version);
			},

			MenApp: {
				get() {
					return this.MenApp_last;
				},
				set(sel) {
					if (sel == null) this.MenApp_last = 0;
					else this.MenApp_last = sel;
					
					return sel;
				}
			},

			mitsPre: function() {
				var mits = [];

				for (const short of this.MenPre) if (this.pnlpre.statshr["Txt" + short + "Avail"]) mits.push(short);

				return mits
			}
		},

		data: () => ({
			initdone: false,
			initdonePnls: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/

			MenApp_last: 0,

			/*
			*/
			MenPre: ["Prd"],
			/*
			*/

			/*
			*/
			MenCrd: [
				{
					pnlsref: "pnladmin",
					mits: ["MitCrdUsg", "MitCrdUsr", "MitCrdPrs"]
				},
				{
					pnlsref: "pnlmon",
					mits: ["MitCrdPrd", "MitCrdEvt", "MitCrdJob", "MitCrdCal", "MitCrdCln", "MitCrdOpx", "MitCrdPst", "MitCrdNde"]
				}
			],
			/*
			*/

			/*
			*/
			pnlheadbar: {
			},

			pnlpre: {
				statshr: null
			},

			pnladmin: {
			},

			pnlmon: {
			},

			/*
			*/

			content: {
				sref: "",
				scrJref: "",

				statshr: null,

				pnlheadbar: {
					initdone: false
				},

				initdone: false
			},

			/*
			*/
			MbarUsg: [
			],

			MbarUsr: [
			],

			MbarPrs: [
			],

			MbarPrd: [
			],

			MbarEvt: [
			],

			MbarJob: [
			],

			MbarCal: [
			],

			MbarCln: [
			],

			MbarOpx: [
			],

			MbarPst: [
			],

			MbarNde: [
			],

			/*
			*/

			MbarContent: null,

			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
