const db=wx.cloud.database()//连接数据库
var app = getApp()
Page({  /**
   * 页面的初始数据
   */
  data: {
    src:"",
    dataObj:"",
    imgUrl:'',
    tupians:[],
    items: [
      {value: '闲置交易', name: '闲置交易' },
      {value: '烦恼咨询', name: '烦恼咨询' },
      {value: '热点新闻', name: '热点新闻'},
      {value: '其他话题', name: '其他话题'}
    ],
    kind:'其他话题' ,
    xing:''
  },
  radioChange(e) {
    const _this=this;
    console.log('radio发生change事件，携带value值为：', e.detail.value)
  _this.setData({
    kind:e.detail.value
    })
    console.log('新的东西',_this.__data__.kind)
    // const items = this.data.items
    // for (let i = 0, len = items.length; i < len; ++i) {
    //   items[i].checked = items[i].value === e.detail.value
    // }
  
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
_chooseImg:function(){
  var that=this;
  wx.chooseImage({
    count: 9,
    sizeType:['original','compressed'],
    sourceType:['album','camera'],
    success(res){
      wx.showToast({
        title: '已放入数据库中',
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
   console.log("这个是",res)
  // var title=res.detail.value.title;
  // var author=res.detail.value.author;
  // var desc=res.detail.value.desc;
  // var {title,author,content}=res.detail.value;
var creatime=this._getCurrentTime()
if(app.globalData.userInfo.xingbie=='男')
{
  _this.setData({
    xing:'/image/man.png'
    })
}
if(app.globalData.userInfo.xingbie=='女')
{
  _this.setData({
    xing:'/image/nu.png'
    })
}

db.collection("homelist").add({
  data:
 {  
   faceImg:app.globalData.userInfo.faceImg,
    image:_this.data.tupians,
    title:res.detail.value.title,
    author:res.detail.value.author,
    desc:res.detail.value.desc,
    creatime:creatime,
    pinglun:[],
   kind:_this.data.kind,
   xing:_this.data.xing
  }
}).then(res=>{
  console.log(res)
})
wx.showToast({
  title: '过一会将会发布',
})
wx.navigateBack()
},  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {
    
  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {
    
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