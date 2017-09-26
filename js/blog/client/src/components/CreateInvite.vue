<template>

<div class="create-invite">

  Invittion vlid for:
  <br>
  <select v-model="validFor">
    <option disabled value="">Please select one</option>
    <option value="0">Hour</option>
    <option>Day</option>
    <option>Week</option>
  </select>

  <br>
  <br>
  Use this pseudo to invite:
  <br>
  <select v-model="underPseudo">
    <option disabled value="">Please select one</option>
    <option v-for="pseudo in currentUser.pseudos" v-bind:value="pseudo.name">
      {{ pseudo.name }}
    </option>
  </select>

  <br>
  <br>
  Select invite type:
  <br>
  <input id="inviteTypeEmail" type="radio" v-model="inviteType" v-bind:value="0">
  <label for="inviteTypeEmail">Email</label>
  <br>
  <input id="inviteTypeLink" type="radio" v-model="inviteType" v-bind:value="1">
  <label for="inviteTypeLink">Link</label>

  <br>
  Name of the person: <br>
  <input type="text" v-model="name">

  <button v-on:click="handleCreateInvitation">Invite</button>

</div>
</template>
<script>
import { createInvitation } from '../utils/trust-api'

export default {
  name: 'create-invite',
  data() {
    return {
      msg: 'Create invitation',
      underPseudo: '',
      validFor: 0,
      inviteType: 0,
      name: ''
    }
  },
  methods: {
    handleCreateInvitation() {
      createInvitation({
        inviterPseudo: this.underPseudo,
        inviteType: this.inviteType,
        comment: this.comment,
        expires_at: 1
      }).then((data) => {
        localStorage.setItem('currentUser', JSON.stringify(data.user))
      })
    }
  },
  computed: {
    // a computed getter
    currentUser: function () {
      return JSON.parse(localStorage.getItem('currentUser'))
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
  .create-invite {
    text-align: left;
    padding: 20px;
    float: left;
  }

  select {
    width: 190px;
  }
</style>
