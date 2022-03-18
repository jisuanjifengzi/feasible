// app.js
App({
  onLaunch(){
  wx.cloud.init({
    env:"cloud1-7gp41k08a5f40651"
  })
 
  this.globalData.userInfo = wx.getStorageSync('userInfo')
  
  },
  globalData:{
    userInfo:null,
    yanzhenInfo:null
  }
})
