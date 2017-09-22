import Vue from 'vue'
import Router from 'vue-router'
import Browser from '@/components/Browser'
import Test from '@/components/Test'
import Contacts from '@/components/Contacts'
import CreateInvite from '@/components/CreateInvite'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'Browser',
      component: Browser
    },
    {
      path: '/test',
      name: 'Test',
      component: Test
    },
    {
      path: '/contacts',
      name: 'Contacts',
      component: Contacts
    },
    {
      path: '/invite/create',
      name: 'create-invite',
      component: CreateInvite

    }
  ]
})
