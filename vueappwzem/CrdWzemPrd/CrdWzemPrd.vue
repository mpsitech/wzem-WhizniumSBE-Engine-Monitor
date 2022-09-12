<template>
	<v-container v-if="initdone">
		<PnlWzemPrdList
			v-on:request="handleRequest"
			ref="PnlWzemPrdList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzemPrdRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzemPrdRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	*/
	import PnlWzemPrdList from './PnlWzemPrdList';
	import PnlWzemPrdRec from './PnlWzemPrdRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzemPrd',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemPrdList,
			PnlWzemPrdRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzemPrd.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWzemPrd) this.continf = dpcheng.ContInfWzemPrd;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzemPrd) this.statapp = dpcheng.StatAppWzemPrd;
				if (dpcheng.StatShrWzemPrd) this.statshr = dpcheng.StatShrWzemPrd;
				if (dpcheng.TagWzemPrd) {
					Wzem.unescapeBlock(dpcheng.TagWzemPrd);
					this.tag = dpcheng.TagWzemPrd;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzemPrdList.handleReply(obj);
					else this.$refs.PnlWzemPrdRec.handleReply(obj);
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
					if (obj.srefIxWzemVDpch == "DpchEngWzemPrdData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzemPrdList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzemPrdRec.handleUpdate(obj);
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
