<template>
	<v-container v-if="initdone">
		<PnlWzemPrsList
			v-on:request="handleRequest"
			ref="PnlWzemPrsList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzemPrsRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzemPrsRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	*/
	import PnlWzemPrsList from './PnlWzemPrsList';
	import PnlWzemPrsRec from './PnlWzemPrsRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzemPrs',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemPrsList,
			PnlWzemPrsRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzemPrs.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWzemPrs) this.continf = dpcheng.ContInfWzemPrs;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzemPrs) this.statapp = dpcheng.StatAppWzemPrs;
				if (dpcheng.StatShrWzemPrs) this.statshr = dpcheng.StatShrWzemPrs;
				if (dpcheng.TagWzemPrs) {
					Wzem.unescapeBlock(dpcheng.TagWzemPrs);
					this.tag = dpcheng.TagWzemPrs;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzemPrsList.handleReply(obj);
					else this.$refs.PnlWzemPrsRec.handleReply(obj);
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
					if (obj.srefIxWzemVDpch == "DpchEngWzemPrsData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzemPrsList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzemPrsRec.handleUpdate(obj);
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
