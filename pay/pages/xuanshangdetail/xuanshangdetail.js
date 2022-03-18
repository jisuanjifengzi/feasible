// pages/xuanshangdetail/xuanshangdetail.js
let ID=''
Page({

  /**
   * 页面的初始数据
   */
  data: {
    detail:'',
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    ID=options.id
    console.log("详情接受的id",options)
    wx.cloud.database().collection("xuanshang")
    .doc(ID)
    .get()
    .then(res=>{
   console.log("详情页成功",res) 
   this.setData({  
     detail:res.data,
   })
   })
   .catch(res=>{
     console.log("详情页失败",res)
   })
  },
  contact(){
    console.log("点击获取的数据用户ID",ID)
    wx.navigateTo({
      url:'/pages/chat/chat?id='+ID
    })
  },
  preview(){ 
    wx.cloud.database().collection('xuanshang').doc(ID).get({
      success(res){
        console.log(res)
        console.log(res.data.image[0])
        wx.previewImage({
          current: '', 
          urls: res.data.image
        })
      }
    })
  },
})