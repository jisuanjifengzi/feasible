const app = getApp()
Page({

  data: {
    yanzhenInfo:'',
  
  },
  
  onShow(){
    this.setData({
      yanzhenInfo:app.globalData.yanzhenInfo,
  
    })
    this.gettieziList()
  },
  goDetail(event){
    console.log("这是你的帖子",event)
    wx.navigateTo({
      url:'/pages/detail/detail?id='+event.currentTarget.dataset.id._id
    })
  },
  gettieziList(){
    var that = this
    wx.cloud.database().collection('homelist').where({_openid:app.globalData.userInfo._openid}).orderBy('creatime','desc').get({
      success(res){
        console.log(res)
        that.setData({
         tieziList: res.data
        })
      }
    })
  },
  removeItem(event){
    let idbase=event.currentTarget.dataset.id
wx.cloud.database().collection('homelist').doc(idbase).remove() 
console.log('已删除')
this.gettieziList()
  }
})