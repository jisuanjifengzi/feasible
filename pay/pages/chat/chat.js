const util = require("../../utils/util")
const app = getApp()
Page({

  data: {
    ID:''
  },
  onShow(){
    this.setData({
      userInfo: app.globalData.userInfo
    })
    
  },
  onLoad: function (options) {
    console.log(options.id)

      this.data.ID=options.id

    this.getChatRecord()

  },

  getChatRecord(){

    var that = this;
    wx.cloud.database().collection('chat_record').where({_tzid:this.data.ID}).get({
      success(res){
        console.log('成功连接',res)
        that.setData({
          chatList: res.data[0]._record
        })
      }
    })
  },


  getInputValue(event){

    console.log(event.detail.value)

    this.data.inputValue = event.detail.value
    
  },
  publishChat(){
    var that = this;
    wx.cloud.database().collection('chat_record').where({_tzid:this.data.ID}).get({
      success(res){
        console.log(res)
        var record = res.data[0]._record
        console.log(record)
        var msg = {}
        msg.userId = app.globalData.userInfo._id
        msg.nickName = app.globalData.userInfo.name
        msg.faceImg = app.globalData.userInfo.faceImg
        msg.openid = app.globalData.userInfo._openid
        msg.text = that.data.inputValue
        msg.time = util.formatTime(new Date())

        record.push(msg)
        console.log(record)
        console.log(res.data[0]._id)
        
        wx.cloud.database().collection('chat_record').doc(res.data[0]._id).update({
          data: {
            _record: record
          },
          success(res){
            console.log(res)
            wx.showToast({
              title: '发布成功！',
            })
            console.log('userInfo',app.globalData.userInfo)
            //刷新下
            that.getChatRecord()

            that.setData({
              inputValue :'',
              plcaceHolder:'评论'
            })
          }
        })


      }
    })

    


  },
})