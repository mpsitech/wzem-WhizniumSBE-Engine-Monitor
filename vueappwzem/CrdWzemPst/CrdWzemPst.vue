<template>
	<v-container v-if="initdone">
		<PnlWzemPstList
			v-on:request="handleRequest"
			ref="PnlWzemPstList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzemPstRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzemPstRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	*/
	import PnlWzemPstList from './PnlWzemPstList';
	import PnlWzemPstRec from './PnlWzemPstRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzemPst',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemPstList,
			PnlWzemPstRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzemPst.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWzemPst) this.continf = dpcheng.ContInfWzemPst;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzemPst) this.statapp = dpcheng.StatAppWzemPst;
				if (dpcheng.StatShrWzemPst) this.statshr = dpcheng.StatShrWzemPst;
				if (dpcheng.TagWzemPst) {
					Wzem.unescapeBlock(dpcheng.TagWzemPst);
					this.tag = dpcheng.TagWzemPst;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzemPstList.handleReply(obj);
					else this.$refs.PnlWzemPstRec.handleReply(obj);
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
					if (obj.srefIxWzemVDpch == "DpchEngWzemPstData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzemPstList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzemPstRec.handleUpdate(obj);
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
