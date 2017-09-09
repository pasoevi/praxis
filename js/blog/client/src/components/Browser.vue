<template>
<div class="browser">

  <div id="vue-frame">
    <div class="toolbar">
      <ul class="menu">
        <li>Bookmarks</li>
        <li>Contacts</li>
        <li>History</li>
        <li>
          <input v-model="url" @keyup.enter="submit">
          <vue-frame text="Go" v-bind:url="url" frame="webview" type="button" class="form-control"></vue-frame>
        </li>
      </ul>
    </div>
    <iframe id="webview"></iframe>
  </div>
  <br>
</div>
</template>
<script>
import VueFrame from 'vue-frame'

export default {
  name: 'browser',
  components: {
    VueFrame
  },
  data () {
    return {
      url: 'http://racket-lang.org',
      msg: 'Welcome to Your Vue.js App'
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.browser {
  float: left;
  width: 80%;
}

h1,
h2 {
  font-weight: normal;
}

#webview {
  width: 100%;
  height: 600px;
  border: 0;
}

ul {
  list-style-type: none;
  padding: 0;
}

li {
  display: inline-block;
  margin: 0 0;
}

a {
  color: #42b983;
}
</style>
