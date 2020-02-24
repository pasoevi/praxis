/*
action - (resolve, reject) => {}
*/
function SimplePromise(action) {
  this.status = 'pending'
  this.result = undefined
  this.thenCallbacks = []
  this.catchCallback = undefined
  this.finallyCallback = undefined

  let resolve = value => {
    this.status = 'resolved'
    this.result = value
    for (let callback of this.thenCallbacks) {
      if (typeof callback === 'function') {
        callback(value)
      }
    }

    if (typeof this.finallyCallback === 'function') {
      this.finallyCallback(value)
    }
  }

  let reject = value => {
    this.status = 'rejected'
    this.result = value

    if (typeof this.catchCallback === 'function') {
      this.catchCallback(value)
    }

    if (typeof this.finallyCallback === 'function') {
      this.finallyCallback(value)
    }
  }

  action(resolve, reject)

  this.then = callback => {
    this.thenCallbacks.push(callback)
    return this
  }

  this.catch = callback => {
    this.catchCallback = callback
    return this
  }

  this.finally = callback => {
    this.finallyCallbacks.push(callback)
    return this
  }
}

const myPromise = new SimplePromise(function(resolve, reject) {
  setTimeout(function() {
    if (Math.floor(Math.random() * 200) % 2 === 0) {
      resolve('Good')
    } else {
      reject('Bad')
    }
  })
})

myPromise
  .then(result => {
    console.log(result)
  })
  .catch(result => {
    console.error(result)
  })
