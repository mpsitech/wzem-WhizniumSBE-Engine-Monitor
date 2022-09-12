<template>
	<v-app>
		<v-main>
			<!-- srefIxVSge prop for CrdWzemStart, others for SessWzem -->
			<component
				v-bind:is="content"
				v-on:login="handleLogin"
				v-on:logout="handleLogout"
				ref="content"
				:srefIxVSge_initial=srefIxVSge
				:scrJrefSess=scrJrefSess
				:scrJrefCrdnav=scrJrefCrdnav
				:srefCrd_initial=srefCrd
				:scrJrefCrd_initial=scrJrefCrd
			/>
		</v-main>
	</v-app>
</template>

<script>
	import Wzem from './scripts/Wzem';

	import CrdWzemStart from './components/CrdWzemStart/CrdWzemStart';
	import SessWzem from './components/SessWzem';

	export default {
		name: 'AppWzem',

		components: {
			CrdWzemStart,
			SessWzem
		},

		beforeMount() {
			document.title = Wzem.title + " v" + Wzem.version;

			// possible keys: scrJrefSess, scrJrefCrdnav, srefCrd, scrJrefCrd
			const params = new URLSearchParams(window.location.search);
			//params.forEach(function(value, key) {console.log(key + ": " + value)});

			this.childNotParent = params.has("scrJrefSess");

			if (!this.childNotParent) this.content = "CrdWzemStart";
			else {
				this.scrJrefSess = params.get("scrJrefSess");
				this.scrJrefCrdnav = params.get("scrJrefCrdnav");

				this.srefCrd = params.get("srefCrd");
				this.scrJrefCrd = params.get("scrJrefCrd");

				this.content = "SessWzem";
			}
		},

		methods: {
			handleLogin(obj) {
				//console.log("AppWzem.handleLogin() received login event with scrJrefSess = " + scrJrefSess);

				this.scrJrefSess = obj.scrJrefSess;
				this.scrJrefCrdnav = obj.scrJrefCrdnav;

				this.srefCrd = "";
				this.scrJrefCrd = "";

				this.content = "SessWzem"
			},

			handleLogout() {
				if (!this.childNotParent) {
					this.srefIxVSge = "term";

					this.scrJrefSess = "";
					this.scrJrefCrdnav = "";

					this.srefCrd = "";
					this.scrJrefCrd = "";

					this.content = "CrdWzemStart"

				} else window.open("about:blank", "_self");
			}
		},

		data: () => ({
			childNotParent: false,	

			content: "",

			srefIxVSge: "idle",

			scrJrefSess: "",
			scrJrefCrdnav: "",

			srefCrd: "",
			scrJrefCrd: ""
		})
	};
</script>
