<template>
  <div id="app">
    <!-- <toolbar></toolbar> -->
    <sidebar></sidebar>
    <router-view></router-view>
  </div>
</template>

<script>

import Toolbar from './components/Toolbar.vue'
import Sidebar from './components/Sidebar.vue'

export default {
  name: 'app',
  components: {
    Toolbar,
    Sidebar
  }
}
</script>

<style>
body {
  margin: 0;
}


#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
</style>
