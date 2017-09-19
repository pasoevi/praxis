<template>
<div class="history">
  <ul>
    <li v-for="item in items">{{item.name}}</li>
  </ul>
</div>
</template>

<script>
export default {
  name: 'history',
  data () {
    return {
      items: [{
        name: 'gmail.com'
      },
      {
        name: 'godaddy.com'
      }
      ]
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
</style>
