//
// Created by LEI XU on 4/27/19.
//

#ifndef RASTERIZER_TEXTURE_H
#define RASTERIZER_TEXTURE_H
#include "global.hpp"
#include <eigen3/Eigen/Eigen>
#include <opencv2/opencv.hpp>
class Texture{
private:
    cv::Mat image_data;

public:
    Texture(const std::string& name)
    {
        image_data = cv::imread(name);
        cv::cvtColor(image_data, image_data, cv::COLOR_RGB2BGR);
        width = image_data.cols;
        height = image_data.rows;
    }

    int width, height;

    Eigen::Vector3f getColor(float u, float v)
    {
        u = fmin(1, fmax(u, 0));
        v = fmin(1, fmax(v, 0));

        auto u_img = u * width;
        auto v_img = (1 - v) * height;
        auto color = image_data.at<cv::Vec3b>(v_img, u_img);
        return Eigen::Vector3f(color[0], color[1], color[2]);
    }

    Eigen::Vector3f getColorBilinear(float u, float v)
    {
        if (u < 0) u = 0;
		if (u > 1) u = 1;
		if (v < 0) v = 0;
		if (v > 1) v = 1;

        float u_img = u * width;
        float v_img = (1 - v) * height;

        float u_min = std::floor(u_img);
		float u_max = std::min((float)width, std::ceil(u_img));
		float v_min = std::floor(v_img);
		float v_max = std::min((float)height, std::ceil(v_img));

        auto u00 = image_data.at<cv::Vec3b> (v_max, u_min);
        auto u01 = image_data.at<cv::Vec3b> (v_max, u_max);
        auto u10 = image_data.at<cv::Vec3b> (v_min, u_min);
        auto u11 = image_data.at<cv::Vec3b> (v_min, u_max);

        float s = (u_img - u_min) / (u_max - u_min);
		float t = (v_img - v_max) / (v_min - v_max);

        auto u0 = (1-s)*u00 + s*u10; // at the top
        auto u1 = (1-s)*u01 + s*u11; // at the bottom 

        auto res = (1-t)*u1 + t*u0;

        return Eigen::Vector3f(res[0], res[1], res[2]);
    } 

};
#endif //RASTERIZER_TEXTURE_H
