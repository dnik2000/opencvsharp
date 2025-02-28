﻿using OpenCvSharp.Quality;
using Xunit;

namespace OpenCvSharp.Tests.Quality
{
    public class QualityGMSDTest : TestBase
    {
        [Fact]
        public void Compute()
        {
            using (var refImage = Image("lenna.png"))
            using (var targetImage = new Mat())
            using (var psnr = QualityGMSD.Create(refImage))
            {
                Cv2.GaussianBlur(refImage, targetImage, new Size(5, 5), 15);

                var value = psnr.Compute(targetImage);
                Assert.Equal(0.062108, value[0], 6);
                Assert.Equal(0.071585, value[1], 6);
                Assert.Equal(0.060303, value[2], 6);
            }
        }

        [Fact]
        public void StaticCompute()
        {
            using (var refImage = Image("lenna.png"))
            using (var targetImage = new Mat())
            {
                Cv2.GaussianBlur(refImage, targetImage, new Size(5, 5), 15);

                var value = QualityGMSD.Compute(refImage, targetImage, null);
                Assert.Equal(0.062108, value[0], 6);
                Assert.Equal(0.071585, value[1], 6);
                Assert.Equal(0.060303, value[2], 6);
            }
        }
    }
}