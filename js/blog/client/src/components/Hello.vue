<template>
  <div class="hello">

    <div id="vue-frame">
      <div class="toolbar">


        <input v-model="url">
        <vue-frame text="Go" v-bind:url="url" frame="webview" type="button" class="form-control"></vue-frame>
      </div>
      <iframe id="webview">

        OK

        <h1>{{ msg }}</h1>

      </iframe>
    </div>
    <br>
  </div>

</template>
<script>
  import VueFrame from 'vue-frame'

  export default {
    name: 'hello',
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

  .hello {
    float: right;
  }

  h1, h2 {
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
