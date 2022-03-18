// pages/chakandetail/chakandetail.js
Page({
  data: {
    imgArr:[
     'https://s2.loli.net/2022/02/22/eEcvVWi7bgU4xJt.png',
'https://s2.loli.net/2022/01/21/BXdWp6yz2tLcORx.png',
'https://s2.loli.net/2022/02/12/dizDMUnr8oLYQ3x.png',
'https://s2.loli.net/2022/02/22/8jbBOZDQwzfSJmP.png'
 ]
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },
  chakan:function(e){ 
    console.log(e)
    let num=e.currentTarget.dataset.number;
    let that=this;
    console.log('所有的图片',that.data.imgArr[0])
    wx.previewImage({
      current:'',   //当前图片地址
      urls: [that.data.imgArr[num]],        //所有要预览的图片的地址集合 数组形式
     })
  },
  /**
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