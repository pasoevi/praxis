<template>
  <div class="contacts">
    <table>
      <thead>
      <tr>
        <th>Under</th>
        <th>Pseudo</th>
        <th>Nickname</th>
        <th>Since</th>
        <th>Note</th>
      </tr>
      </thead>
      <tbody>
      <tr v-for="contact in contacts">
        <td>{{ currentUser.pseudos[0].name }}</td>
        <td>{{ contact.pseudos[0].name }}</td>
        <td>{{ contact.pseudos[0].nickName }}</td>
        <td>{{ contact.registration_time }}</td>
        <td>{{ contact.comment }}</td>
      </tr>
      </tbody>
    </table>
    <router-link to="/invite/create">Invite</router-link>
  </div>
</template>

<script>
  import { getContacts } from '../utils/trust-api'

  export default {
    name: 'contacts',
    data() {
      return {
        contacts: ''
      }
    },
    methods: {
      handleGetContacts() {
        let self = this
        getContacts().then(function (data) {
          self.contacts = data.contacts
          console.log(data.contacts)
        })
      }
    },
    computed: {
      // a computed getter
      currentUser: function () {
        return JSON.parse(localStorage.getItem('currentUser'))
      }
    },
    created: function () {
      this.handleGetContacts()
    }
  }
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
</style>
