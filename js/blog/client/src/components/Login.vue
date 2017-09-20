<template>
  <div class="login">
    <button @click="handleLogin"></button>
  </div>
</template>

<script>
  import { login } from '../utils/auth-api'

  export default {
    name: 'login',
    data() {
      return {
        contacts: []
      }
    },
    methods: {
      handleLogin() {
        login('admin', 'admin1').then((user) => {
//          this.publicBattles = battles;
          alert(user)
        })
      }
    }
  }
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
</style>
