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
        <td>{{ contact.username }}</td>
        <td>{{ contact.username }}</td>
        <td>{{ contact.registration_time }}</td>
        <td>{{ contact.username }}</td>
      </tr>
      </tbody>
    </table>
    <ul>
    </ul>
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
    created: function () {
      this.handleGetContacts()
    }
  }
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
</style>
