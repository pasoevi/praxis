import axios from 'axios'

const API_VERSION = 'v1'
const BASE_URL = `http://localhost:8000/api/${API_VERSION}`

const config = {
  headers: {
    'Accept': 'application/json',
    'Content-Type': 'application/json'
    // 'Access-Control-Allow-Origin': '*'
  },
  withCredentials: true
}

export { getContacts, getBookmarks, createInvitation }

function getContacts() {
  const url = `${BASE_URL}/get_contacts_list`
  // return axios.get(url).then(response => response.data)
  return axios.get(url, config).then(response => response.data)
}

function getBookmarks() {
  const url = `${BASE_URL}/api/battles/private`
  return axios.get(url).then(response => response.data)
}

function createInvitation(invitation) {
  const url = `${BASE_URL}/create_invitation`
  // return axios.get(url).then(response => response.data)
  return axios.post(url, {invitationData: invitation}, config).then(response => response.data)
}
