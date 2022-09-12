<template>
	<v-container v-if="initdone">
		<PnlWzemCalList
			v-on:request="handleRequest"
			ref="PnlWzemCalList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzemCalRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzemCalRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzem from '../../scripts/Wzem';

	/*
	*/
	import PnlWzemCalList from './PnlWzemCalList';
	import PnlWzemCalRec from './PnlWzemCalRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzemCal',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzemCalList,
			PnlWzemCalRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzemCal.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWzemCal) this.continf = dpcheng.ContInfWzemCal;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzemCal) this.statapp = dpcheng.StatAppWzemCal;
				if (dpcheng.StatShrWzemCal) this.statshr = dpcheng.StatShrWzemCal;
				if (dpcheng.TagWzemCal) {
					Wzem.unescapeBlock(dpcheng.TagWzemCal);
					this.tag = dpcheng.TagWzemCal;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzemCalList.handleReply(obj);
					else this.$refs.PnlWzemCalRec.handleReply(obj);
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
					if (obj.srefIxWzemVDpch == "DpchEngWzemCalData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzemCalList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzemCalRec.handleUpdate(obj);
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
