<template>
<div class="contacts">
  <ul>
  <li v-for="contact in contacts">{{contact.name}}</li>
</ul>
</div>
</template>

<script>
export default {
  name: 'contacts',
  data () {
    return {
      contacts: [{
        name: 'Sergi'
      },
      {
        name: 'Sylvain'
      }
      ]
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

ul {
  list-style-type: none;
  padding: 0;
}
</style>
