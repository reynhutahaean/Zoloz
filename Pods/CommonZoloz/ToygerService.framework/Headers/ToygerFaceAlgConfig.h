//
//  ToygerFaceAlgConfig.h
//  ToygerService
//
//  Created by yukun.tyk on 2018/7/5.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ToygerFaceAlgConfig : NSObject

@property (nonatomic, copy) NSString *stack_time;
@property (nonatomic, copy) NSString *blink_openness;
@property (nonatomic, copy) NSString *diff_threshold;
@property (nonatomic, copy) NSString *eye_openness;
@property (nonatomic, copy) NSString *pose_pitch;
@property (nonatomic, copy) NSString *pose_yaw;
@property (nonatomic, copy) NSString *pose_gaussian;
@property (nonatomic, copy) NSString *liveness_combinations;
@property (nonatomic, copy) NSString *pose_motion;
@property (nonatomic, copy) NSString *pose_pitchMin;
@property (nonatomic, copy) NSString *pose_rectwidth;
@property (nonatomic, copy) NSString *pose_integrity;
@property (nonatomic, copy) NSString *pose_light;
@property (nonatomic, copy) NSString *pose_yawMin;
@property (nonatomic, copy) NSString *log_level;
@property (nonatomic, copy) NSString *min_iod;
@property (nonatomic, copy) NSString *max_iod;
@property (nonatomic, copy) NSString *blink_openness_threshold_aux;
@property (nonatomic, copy) NSString *blink_diff_threshold_aux;
@property (nonatomic, copy) NSString *quality_stability_threshold;
@property (nonatomic, copy) NSString *quality_min_quality;
@property (nonatomic, copy) NSArray<NSString *> *liveness_combination;
@property (nonatomic, copy) NSDictionary *threshold;
@property (nonatomic, copy) NSArray *liveness_action_combination;
@property (nonatomic, copy) NSArray<NSString *> *data_collection;
@property (nonatomic, copy) NSString *eye_occlusion_score_threshold;
@property (nonatomic, copy) NSString *pts_occ_num_threshold;

@property (nonatomic, copy) NSString *face_confidence_threshold;

@end

