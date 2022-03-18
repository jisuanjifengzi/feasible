const app = getApp()
Page({

  data: {
    yanzhenInfo:''
  },
  onShow(){
    this.setData({
      yanzhenInfo:app.globalData.yanzhenInfo
    })
    this.gettieziList()
  },

  gettieziList(){
    var that = this
    wx.cloud.database().collection('xuanshang').where({_openid:app.globalData.userInfo._openid})
    .orderBy('creatime','desc').get({
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
    // let openid=app.globalData.userInfo._openid
wx.cloud.database().collection('xuanshang').doc(idbase).remove() 
console.log('已删除')
 this.gettieziList(); 
  },
 goDetail(event){
    wx.navigateTo({
      url:'/pages/xuanshangdetail/xuanshangdetail?id='+event.currentTarget.dataset.id._id
    })
  }
}) 