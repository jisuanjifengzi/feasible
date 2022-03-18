// pages/xuanshang/xuanshang.js
const db=wx.cloud.database()//连接数据库
const app = getApp()
Page({

  /**
   * 页面的初始数据
   */
  data: { 
    fuqian:'',
    userInfo:'',
    imgUrl:'',
  tupians:[]
  },
  _getCurrentTime(){
    var d=new Date();
    var month=d.getMonth()+1;
    var date=d.getDate();
    var day=d.getDay();
    var hours=d.getHours();
    var minutes=d.getMinutes();
    var second=d.getSeconds();
    var ms=d.getUTCMilliseconds;
var curDateTime=d.getFullYear()+'年';
if(month>9)
curDateTime+=month+'月';
else
curDateTime+=month+'月';
if(date>9)
curDateTime=curDateTime+date+"日";
else
curDateTime=curDateTime+date+"日";
if(hours>9)
curDateTime=curDateTime+hours+"时";
else
curDateTime=curDateTime+hours+"时";
if(minutes>9)
curDateTime=curDateTime+minutes+"分";
else
curDateTime=curDateTime+minutes+"分";
return curDateTime;
  }, 

  goPay(){
      var that=this;
      const _this=this;
   wx.cloud.callFunction({
        name: 'pay0611',
        success: res => {
          console.log("获取支付参数成功",res)
          const payment = res.result.payment
          //调起支付
          wx.requestPayment({
            ...payment,
            success (res) {
              console.log('支付成功', res)
              that.setData({
                fuqian:1
              })
            },
            fail (res) {
              console.error('支付失败', res)
            }
          })
        },
        fail: console.error,
      })
      return _this.data.fuqian
    },
  _chooseImg:function(){
    var that=this;
    wx.chooseImage({
      count: 9,
      sizeType:['original','compressed'],
      sourceType:['album','camera'],
      success(res){
        wx.showToast({
          title: '图片将放入数据库中',
        })
        var  tempFilePaths=res.tempFilePaths
that.setData({
  tupians:tempFilePaths
})
      }
    })
    // var that=this
    //   wx.chooseImage({
    //   count:1,//最多选择9张图片
    //   sizetype:['original','compressed'],//图片支持原图和压缩图
    //   sourceType:['album','camera'],//图片来源是相机和相册
    //   success(res){
    //     console.log(res)
    //     wx.showLoading({
    //       title:'上传中',
    //     })
    //     const filePath=res.tempFilePaths[0]
    //   that.setData({
    //   imgUrl:filePath
    //   })
    //   let cloudPath=new Date().getTime+'.'+filePath.match(/\.[^.]+?$/)[0]
    //   console.log("cloudPath",cloudPath)
    //   wx.cloud.uploadFile({
    //     cloudPath,
    //     filePath,
    //     success: res => {
    //      console.log('[上传文件] 成功：', cloudPath, res)
    //      app.globalData.fileID = res.fileID
    //      app.globalData.cloudPath = cloudPath
    //      app.globalData.imagePath = filePath
    //      console.log(app.globalData.fileID)
    //     },complete:()=>{
    //       wx.hideLoading()
    //       wx.showToast({
    //         title: '已上传数据库',
    //       })
    //     }
    //   })
    //   }
    // })
  },
  btnSub(res){
    const _this=this
    console.log(res)
 var author=res.detail.value.author
 var title=res.detail.value.title
 var desc=res.detail.value.desc
 var money=res.detail.value.money
 var creatime=this._getCurrentTime() 
 if(res.detail.value.title<1){
        wx.showToast({
          icon:"none",
          title: '标题过短',
        })
        return
        } 
 if(res.detail.value.author<1){
      wx.showToast({
        icon:"none",
        title: '姓名过短',
      })
      return
      }
      if(res.detail.value.money<1){
          wx.showToast({
            icon:"none",
            title: '报酬过少',
          })
          return
          } 
      if(res.detail.value.desc<1){
        wx.showToast({
          icon:"none",
          title: '内容过短',
        })
        return
        }
db.collection("xuanshang").add({
  
  data:{
    // image: new Array(app.globalData.fileID), 
    image:_this.data.tupians,
    title:title,
   author:author,
   desc:desc,
   money:money,
   creatime:creatime
  }
  }).then(res=>{
    console.log(res)
    db.collection("chat_record").add({
      data:{
        _tzid:res._id,
        _record:[],
        userid:app.globalData.userInfo._openid
      }
    })
  })
  wx.showToast({
    title: '过一会将会发布',
  })
this.setData({
  fuqian:null
})
wx.navigateBack()
  },
  

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },


  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})