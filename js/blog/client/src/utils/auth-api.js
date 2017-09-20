import axios from 'axios'

const API_VERSION = 'v1'
const BASE_URL = `http://localhost:8000/api/${API_VERSION}`

const config = {
  headers: {
    'Accept': 'application/json',
    'Content-Type': 'application/json'
    // 'Access-Control-Allow-Origin': '*'
  }
}

export { login, logout, signup }

function login(username, password) {
  const url = `${BASE_URL}/login`
  // return axios.get(url).then(response => response.data)
  return axios.post(url, {username: username, password: password}, config).then(response => response.data)
}

function logout() {
  const url = `${BASE_URL}/api/battles/private`
  return axios.get(url).then(response => response.data)
}

function signup() {
  const url = `${BASE_URL}/api/battles/private`
  return axios.get(url).then(response => response.data)
}
