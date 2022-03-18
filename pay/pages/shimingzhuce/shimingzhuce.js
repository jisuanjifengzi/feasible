const app = getApp()
Page({
  data:{
    name:'',
    shenfenzhen:'',
    nianji:'',
    school:'',
    yanzhenInfo:'',
    items: [
      {value: '男', name: '男' },
      {value: '女', name: '女' },
    ],
    kind:'女'
  },
  onLoad(res){ 
    this.setData({
      yanzhenInfo:app.globalData.yanzhenInfo
    })
  },
  radioChange(e) {
    const _this=this;
    console.log('radio发生change事件，携带value值为：', e.detail.value)
  _this.setData({
    kind:e.detail.value
    })
    console.log('用户性别',_this.__data__.kind)  
  },
        //获取用户学校
        getSchool(event){
          console.log("获取用户所在学校",event.detail.value)
          this.setData({
            school:event.detail.value
          })
        },
      //获取用户名
      getName(event){
        console.log("获取用户名",event.detail.value)
        this.setData({
          name:event.detail.value
        })
      },
      //获取用户身份证
      getShenfenzhen(event){
        console.log("获取用户账号",event.detail.value)
        this.setData({
          shenfenzhen:event.detail.value
        })
      },
      //获取用户学号
      getxuehao(event){
        console.log("获取用户学号",event.detail.value)
        this.setData({
         xuehao:event.detail.value
        })
      },
      //获取年级和专业
    getNianji(event){
      console.log("获取年级专业",event.detail.value)
      this.setData({
        nianji:event.detail.value
      })
    },
    xieyi(){
      wx.navigateTo({
        url: '/pages/xieyi/xieyi',
      })
    },
//注册
zhuce(){
  let name=this.data.name
  let shenfenzhen=this.data.shenfenzhen
  let nianji=this.data.nianji
  let school=this.data.school
  let xuehao=this.data.xuehao
  let renzhen=1 
  let xingbie=this.data.kind
  wx.setStorageSync('weiyi', renzhen)
      let user = wx.getStorageSync('user')
      if(school.length<1){
        wx.showToast({
          icon:"none",
          title: '请填写学校',
        })
        return
        }
      if(name.length<1){
        wx.showToast({
          icon:"none",
          title: '请输入姓名',
        })
        return
        } 
        if(xuehao.length<10){
          wx.showToast({
            icon:"none",
            title: '请输入正确的学号',
          })
          return
          }
    
        if(shenfenzhen.length<18){
          wx.showToast({
            icon:"none",
            title: '请输入正确的身份证号',
          })
          return
          }
      if(nianji.length<1){
          wx.showToast({
            icon:"none",
            title: '请输入你的年级及专业',
          })
          return
          } 
      //注册功能实现
      wx.cloud.database().collection('user').add({
        data:{
          name:name,
          shenfenzhen:shenfenzhen,
          nianji:nianji,
          school:school,
          renzhen:renzhen,
          faceImg:user.avatarUrl,
          nickName:user.nickName,
          xuehao:xuehao,
          xingbie:xingbie
        },
        success(res){
         
         wx.cloud.database().collection('user').doc(res._id).get({
           success(res){
             console.log(res)
             wx.setStorageSync('userInfo', res.data)
             app.globalData.userInfo=res.data
             console.log(app.globalData.userInfo)
           }
         })
          wx.showToast({
            title: '注册成功',
          })
         
     
        },
        fail(res){
          wx.showToast({
            icon:"none",
            title: '注册失败',
          })
        }
      })
      app.globalData.yanzhenInfo=1
      wx.navigateBack()
}
})