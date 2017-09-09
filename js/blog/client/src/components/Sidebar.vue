<template>
<div class="sidebar">
  <select v-model="content">
    <option value="contacts">Contacts</option>
  <option value="bookmarks">Bookmarks</option>
  <option value="history">History</option>
</select>

  <div v-if="content === 'contacts'">
    <contacts></contacts>
  </div>
  <div v-else-if="content === 'bookmarks'">
    <bookmarks></bookmarks>
  </div>
  <div v-if="content === 'history'">
    <history></history>
  </div>
</div>
</template>

<script>
import Contacts from './Contacts.vue'
import Bookmarks from './Bookmarks.vue'
import History from './history.vue'

export default {
  name: 'sidebar',
  components: {
    Contacts,
    Bookmarks,
    History
  },
  data () {
    return {
      content: 'contacts'
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.sidebar {
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
