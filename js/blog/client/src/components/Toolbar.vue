<template>
<!-- Currently not used -->
<div class="toolbar">
  <ul class="menu">
    <li>
      <router-link to="/">Home</router-link>
    </li>
    <li>
      <router-link to="/test">Test</router-link>
    </li>
    <li>
      <router-link to="/contacts">Contacts</router-link>
    </li>

    <li>
      <input v-model="url" @keyup.enter="submit">
      <vue-frame text="Go" v-bind:url="url" frame="webview" type="button" class="form-control"></vue-frame>
    </li>
  </ul>
</div>
</template>

<script>
export default {
  name: 'toolbar',
  props: ['content'],
  data() {
    return {
      url: 'http://racket-lang.org',
      msg: 'Navigate across the Web here.'
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.toolbar {
  height: 20px;
}

h1,
h2 {
  font-weight: normal;
}

ul {
  list-style-type: none;
  padding: 0;
}

li {
  display: inline-block;
  margin: 0 10px;
}

a {
  color: #42b983;
}
</style>
