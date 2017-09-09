<template>
<ul class="sidebard">
  <li>Contacts</li>
  <li>Bookmarks</li>
  <li>History</li>
  <li>Settings</li>
</ul>
</template>

<script>
export default {
  name: 'sidebar',
  data () {
    return {
      msg: 'Try different features here'
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.sidebard {
  width: 20%;
  background-color: #ccc;
  height: 600px;
  float: left;
  margin: 0;
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
  /*display: inline-block;*/
  margin: 0 10px;
}

a {
  color: #42b983;
}
</style>
