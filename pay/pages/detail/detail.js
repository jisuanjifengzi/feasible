let ID=''
Page({
  data:{
    xingming:'',
    detail:'',
  content:'',
 pinglun:[]//搞动态刷新。，每添加一次重新显示新的评论列表
  },
onLoad(options){
  ID=options.id
 console.log("详情接受的id",options)
 wx.cloud.database().collection("homelist")
 .doc(ID)
 .get()
 .then(res=>{
console.log("详情页成功",res) 
console.log("openid是",res.data._openid)
this.setData({  
  detail:res.data,
   pinglun:res.data.pinglun
})
})
.catch(res=>{
  console.log("详情页失败",res)
})
  },
    //获取评论的concent 上面有
getContent(event){
      this.setData({
        content:event.detail.value
      })
console.log("获取输入的值",event.detail.value)
},
preview(){ 
  wx.cloud.database().collection('homelist').doc(ID).get({
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
//发表的
fabiao(){
  let mingzhi=wx.getStorageSync('user')
  console.log("名字的",mingzhi),
this.setData
({
   xingming:mingzhi.nickName
})
  let content=this.data.content;//自己定义的一个content名字随便取
  console.log(this.data)
  if(content.length<1){
    wx.showToast({
      icon:"none",
      title: '评论太短',
    })
    return 
  }
  let pinglunItem={}
  pinglunItem.name=this.data.xingming
  pinglunItem.content=content
  let pinglunArr=this.data.pinglun
  pinglunArr.push(pinglunItem)
  console.log("添加后的评论数组",pinglunArr)
  wx.showLoading({
    title:'发表中。。。',
  })
wx.cloud.callFunction({
  name:"caozuo",
  data:{
    action:"fabiao",
    id:ID,//评论的那篇文字的id
    pinglun:pinglunArr
  }
}).then(res=>{
console.log("发表成功",res)
this.setData({
  pinglun:pinglunArr,
  content:''
})
wx.hideLoading()
})
.catch(res=>{
console.log("发表失败",res)
wx.hideLoading()
})
}
})