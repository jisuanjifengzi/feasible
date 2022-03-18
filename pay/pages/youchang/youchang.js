const db=wx.cloud.database()
const app=getApp()
const productsCollection=db.collection('xuanshang')
Page({

  data:{
    home_images:
    ['https://s2.loli.net/2022/02/10/h5vF7oZraKEMRpk.jpg'],
    datalist:[],
    yanzhenInfo:''
  },
  onLoad(){

  },
  onShow(){
    this.setData({
      yanzhenInfo:app.globalData.yanzhenInfo
    })
    wx.cloud.database().collection('xuanshang')
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
    console.log("点击获取的数据用户ID",event.currentTarget.dataset.id._id)
    wx.navigateTo({
      url:'/pages/xuanshangdetail/xuanshangdetail?id='+event.currentTarget.dataset.id._id
    })
  },
  chakan(event){
    wx.navigateTo({
      url: '/pages/chakandetail/chakandetail',
    })
  },
quxuanshang(event){
  wx.navigateTo({
    url: '/pages/xuanshang/xuanshang',
  })
},
onPullDownRefresh:function(){
  productsCollection
  .orderBy('creatime','desc')
  .get()
  .then(res=>{
    this.setData({
      datalist:res.data
    },res=>{
      console.log("数据更新成功")  
    }
    )
    wx.stopPullDownRefresh()
    })
  }
})

