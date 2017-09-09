import Vue from 'vue'
import Router from 'vue-router'
import Browser from '@/components/Browser'
import Test from '@/components/Test'

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
    }
  ]
})
