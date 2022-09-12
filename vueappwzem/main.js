import Vue from 'vue'
import axios from 'axios'
import VueAxios from 'vue-axios'
import AppWzem from './AppWzem.vue'
import vuetify from './plugins/vuetify'

Vue.config.productionTip = false

Vue.use(VueAxios, axios)

new Vue({
	vuetify,
	render: h => h(AppWzem)
}).$mount("#app")
