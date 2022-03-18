const db=wx.cloud.database()
const app=getApp()
const productsCollection=db.collection('homelist')
Page({

  data:{
    datalist:[],
    yanzhenInfo:'',
    faceImg:''
  },
  onShow(){

this.setData({
  yanzhenInfo:app.globalData.yanzhenInfo,
faceImg:app.globalData.userInfo.faceImg
})
    wx.cloud.database().collection('homelist')
    .orderBy('creatime','desc')
    .get()
    .then(res=>{
      console.log("获取成功",res)
      this.setData({
        datalist:res.data
      })
    })
    .catch(res=>{
      console.log("获取失败",res)
    })
  },
  goDetail(event){
    console.log("点击获取的数据",event.currentTarget.dataset.id._id)
    wx.navigateTo({
      url:'/pages/detail/detail?id='+event.currentTarget.dataset.id._id
    })
  },
quxiepinglun(event){
  wx.navigateTo({
    url: '/pages/xiepinglun/xiepinglun',
  })
},
text(){
  console.log('图片内容',app.globalData.userInfo.faceImg)
},
onPullDownRefresh:function(){
  productsCollection.get().then(res=>{
    this.setData({
      datalist:res.data
    },res=>{
      console.log("数据更新成功")
      wx.stopPullDownRefresh()
    }
    )
    })
  }


})

