const app=getApp()
let idbase=''
Page({
  data:{
    userInfo:''
  },
  onLoad(){
    let user=wx.getStorageSync('user')
    this.setData({
      userInfo:user
       })
       if(this.data.userInfo==null){}
       else{
       wx.cloud.database().collection('yanzheng').add({
        data:{},
        success(res){
         wx.cloud.database().collection('yanzheng').doc(res._id).get({
           success(res){
             console.log("验证",res.data._openid)
             wx.cloud.database().collection('user').where({_openid:res.data._openid}).get({
             success(res){
              if(res.data[0]==null)
              {}else
              {
               wx.setStorageSync('userInfo', res.data[0])
               app.globalData.userInfo=res.data[0]
               console.log("USER",res)
               wx.showToast({
                 title: '您已实名',
               })
               app.globalData.yanzhenInfo=1
               console.log('yanzhenInfo',app.globalData.yanzhenInfo)
              }
           },
           fail(){}
         }) 
           }
         })
         wx.cloud.database().collection('yanzheng').doc(res._id).remove()
        }
        })
      }
  },
//   login()
// {
//   let that=this
// console.log('点击事件执行了')
// wx.getUserProfile({
// desc:'必须授权才能继续使用',
// success(res){
// console.log('授权成功',res.userInfo)
// that.setData({
//   nickName:res.userInfo.nickName
// })
// },//老方法写
login()
 {
 wx.getUserProfile({
 desc:'必须授权才能继续使用',
 success:res => {
  let user=res.userInfo
  wx.setStorageSync('user', user)
   this.setData({
      userInfo:res.userInfo
   })
    wx.cloud.database().collection('yanzheng').add({
    data:{},
    success(res){
     wx.cloud.database().collection('yanzheng').doc(res._id).get({
       success(res){
         console.log("验证",res.data._openid)
         wx.cloud.database().collection('user').where({_openid:res.data._openid}).get({
         success(res){
          if(res.data[0]==null)
          {}else
          {
           wx.setStorageSync('userInfo', res.data[0])
           app.globalData.userInfo=res.data[0]
           console.log("USER",res)
           wx.showToast({
             title: '您已实名',
           })
           app.globalData.yanzhenInfo=1
           console.log('yanzhenInfo',app.globalData.yanzhenInfo)
          }
       },
       fail(){}
     }) 
       }
     })
     wx.cloud.database().collection('yanzheng').doc(res._id).remove()
    }
    })
},
fail:res =>{
  console.log('授权失败',res.userInfo)
}
})
},
loginOut(){
  this.setData({
    userInfo:''
  })
  wx.setStorageSync('user', null)
  app.globalData.yanzhenInfo=''
},
shimingzhuce()
{ 
  wx.cloud.database().collection('user')
.where({
  renzhen:1
})
.get({ 
success:console.log,
fail:console.log,
})
   wx.navigateTo({
    url:'/pages/shimingzhuce/shimingzhuce'
  })
},
wuchang()
{
  wx.navigateTo({
    url:'/pages/mytiezi/mytiezi'
  })
},
youchang(){
  wx.navigateTo({
    url:'/pages/myqiuzhu/myqiuzhu'
  })
},
xuanshang(){
  wx.navigateTo({
    url:'/pages/youchang/youchang'
  })
},
home(){
  wx.navigateTo({
    url:'/pages/home/home'
  })
},
toGG(){
  wx.navigateTo({
    url:'/pages/chakandetail/chakandetail'
  })
}
// clearS(){
//   wx.clearStorageSync('user')
//   wx.clearStorageSync('userInfo')
//   console.log(wx.getStorageSync('user'))
// }
})