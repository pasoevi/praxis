<template>
<div class="bookmarks">
  <ul>
    <li v-for="bookmark in bookmarks">{{bookmark.name}}</li>
  </ul>
</div>
</template>

<script>
export default {
  name: 'bookmarks',
  data () {
    return {
      bookmarks: [{
        name: 'Google'
      },
      {
        name: 'Gutenberg'
      }
      ]
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

</style>
