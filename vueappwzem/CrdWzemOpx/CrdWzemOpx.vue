<template>
	<v-container v-if="initdone">
		<PnlWzemOpxList
			v-on:request="handleRequest"
			ref="PnlWzemOpxList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzemOpxRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzemOpxRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	*/
	import PnlWzemOpxList from './PnlWzemOpxList';
	import PnlWzemOpxRec from './PnlWzemOpxRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzemOpx',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemOpxList,
			PnlWzemOpxRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzemOpx.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWzemOpx) this.continf = dpcheng.ContInfWzemOpx;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzemOpx) this.statapp = dpcheng.StatAppWzemOpx;
				if (dpcheng.StatShrWzemOpx) this.statshr = dpcheng.StatShrWzemOpx;
				if (dpcheng.TagWzemOpx) {
					Wzem.unescapeBlock(dpcheng.TagWzemOpx);
					this.tag = dpcheng.TagWzemOpx;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzemOpxList.handleReply(obj);
					else this.$refs.PnlWzemOpxRec.handleReply(obj);
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
					if (obj.srefIxWzemVDpch == "DpchEngWzemOpxData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzemOpxList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzemOpxRec.handleUpdate(obj);
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
