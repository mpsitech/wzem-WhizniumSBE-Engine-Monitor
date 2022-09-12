<template>
	<v-container v-if="initdone">
		<PnlWzemUsgList
			v-on:request="handleRequest"
			ref="PnlWzemUsgList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzemUsgRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzemUsgRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	*/
	import PnlWzemUsgList from './PnlWzemUsgList';
	import PnlWzemUsgRec from './PnlWzemUsgRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzemUsg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemUsgList,
			PnlWzemUsgRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzemUsg.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWzemUsg) this.continf = dpcheng.ContInfWzemUsg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzemUsg) this.statapp = dpcheng.StatAppWzemUsg;
				if (dpcheng.StatShrWzemUsg) this.statshr = dpcheng.StatShrWzemUsg;
				if (dpcheng.TagWzemUsg) {
					Wzem.unescapeBlock(dpcheng.TagWzemUsg);
					this.tag = dpcheng.TagWzemUsg;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzemUsgList.handleReply(obj);
					else this.$refs.PnlWzemUsgRec.handleReply(obj);
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
					if (obj.srefIxWzemVDpch == "DpchEngWzemUsgData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzemUsgList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzemUsgRec.handleUpdate(obj);
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
