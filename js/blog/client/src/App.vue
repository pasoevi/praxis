<template>
<div id="app">
    <input type="checkbox" id="sidebarShown" v-model="sidebarShown">
    <toolbar></toolbar>
    <sidebar v-show="sidebarShown"></sidebar>
    <router-view></router-view>
</div>
</template>

<script>
// import Vue from 'vue'
// import Vuetify from 'vuetify'
import Toolbar from './components/Toolbar.vue'
import Sidebar from './components/Sidebar.vue'
import Contacts from './components/Contacts.vue'
import Bookmarks from './components/Bookmarks.vue'

// Vue.use(Vuetify)

export default {
  name: 'app',
  components: {
    Toolbar,
    Sidebar,
    Contacts,
    Bookmarks
  },
  data () {
    return {
      sidebarShown: false
    }
  }

}
</script>

<style>
body {
  margin: 0;
}

#sidebarShown {
  display: inline;
  float: left;
}

#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
</style>
