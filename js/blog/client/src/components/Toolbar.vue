<template>
  <div class="toolbar">
  </div>
</template>

<script>
export default {
  name: 'toolbar',
  data () {
    return {
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

h1, h2 {
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
