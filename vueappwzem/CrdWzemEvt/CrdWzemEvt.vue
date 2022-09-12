<template>
	<v-container v-if="initdone">
		<PnlWzemEvtList
			v-on:request="handleRequest"
			ref="PnlWzemEvtList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzemEvtRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzemEvtRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	*/
	import PnlWzemEvtList from './PnlWzemEvtList';
	import PnlWzemEvtRec from './PnlWzemEvtRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzemEvt',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemEvtList,
			PnlWzemEvtRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzemEvt.mounted() with scrJref = " + this.scrJref);

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

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfWzemEvt) this.continf = dpcheng.ContInfWzemEvt;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzemEvt) this.statapp = dpcheng.StatAppWzemEvt;
				if (dpcheng.StatShrWzemEvt) this.statshr = dpcheng.StatShrWzemEvt;
				if (dpcheng.TagWzemEvt) {
					Wzem.unescapeBlock(dpcheng.TagWzemEvt);
					this.tag = dpcheng.TagWzemEvt;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzemEvtList.handleReply(obj);
					else this.$refs.PnlWzemEvtRec.handleReply(obj);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzemVDpch == "DpchEngWzemEvtData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzemEvtList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzemEvtRec.handleUpdate(obj);
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzemVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

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
