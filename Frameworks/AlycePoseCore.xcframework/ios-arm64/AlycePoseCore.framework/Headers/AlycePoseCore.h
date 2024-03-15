#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class APCAlycePoseInfo, APCExercise, APCApiClientCompanion, APCExamination, APCPoseDefinition, APCKotlinEnumCompanion, APCKotlinEnum<E>, APCBodyPartCompanion, APCBodyPart, APCKotlinArray<T>, APCKotlinPair<__covariant A, __covariant B>, APCConstant, APCFreezable, APCCoordinate, APCDevice, APCDistanceEvaluatorCompanion, APCKeyPoint, APCRectF, APCEvalResult, APCEvaluateUtilCompanion, APCEvaluatorCompanion, APCExaminationEvaluatorCompanion, APCExerciseType, APCFlipDir, APCOriginalBodyPartCompanion, APCOriginalBodyPart, APCPerson, APCPoseEvalResult, APCSampleExercise, APCTorsoAndBodyDistance, APCUtilCompanion, UIImageView, UIImage, APCAbsoluteAngleCompanion, APCAbsoluteAngle, APCAuthRequestBodyCompanion, APCAuthRequestBody, APCAuthResponseCompanion, APCAuthResponse, APCCategoryCompanion, APCCategory, APCPosition, APCRelativeAngle, APCConditionCompanion, APCCondition, APCInitialPose, APCExaminationCompanion, APCExerciseCompanion, APCInitialPoseCompanion, APCPoseCompanion, APCPose, APCPoseDecoder, APCPoseDefinitionCompanion, APCPositionCompanion, APCRelativeAngleCompanion, APCKotlinThrowable, APCKotlinException, APCKotlinRuntimeException, APCKotlinIllegalStateException, APCKotlinx_serialization_coreSerializersModule, APCKotlinx_serialization_coreSerialKind, APCKotlinNothing;

@protocol APCKotlinComparable, APCConstVisualization, APCDistanceCheckListener, APCAlyceposeListenerInternal, APCExaminationListener, APCConditionBase, APCAngle, APCKotlinx_serialization_coreKSerializer, APCKotlinIterator, APCKotlinx_serialization_coreEncoder, APCKotlinx_serialization_coreSerialDescriptor, APCKotlinx_serialization_coreSerializationStrategy, APCKotlinx_serialization_coreDecoder, APCKotlinx_serialization_coreDeserializationStrategy, APCKotlinx_serialization_coreCompositeEncoder, APCKotlinAnnotation, APCKotlinx_serialization_coreCompositeDecoder, APCKotlinx_serialization_coreSerializersModuleCollector, APCKotlinKClass, APCKotlinKDeclarationContainer, APCKotlinKAnnotatedElement, APCKotlinKClassifier;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface APCBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface APCBase (APCBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface APCMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface APCMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorAPCKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface APCNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface APCByte : APCNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface APCUByte : APCNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface APCShort : APCNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface APCUShort : APCNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface APCInt : APCNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface APCUInt : APCNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface APCLong : APCNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface APCULong : APCNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface APCFloat : APCNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface APCDouble : APCNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface APCBoolean : APCNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AlycePoseInfo")))
@interface APCAlycePoseInfo : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)alycePoseInfo __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCAlycePoseInfo *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *VERSION_NAME __attribute__((swift_name("VERSION_NAME")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AlyceTimer")))
@interface APCAlyceTimer : APCBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)invalidate __attribute__((swift_name("invalidate()")));
- (void)scheduleTimeIntervalMs:(double)timeIntervalMs repeat:(BOOL)repeat task:(void (^)(void))task __attribute__((swift_name("schedule(timeIntervalMs:repeat:task:)")));
@end

__attribute__((swift_name("AlyceposeListenerInternal")))
@protocol APCAlyceposeListenerInternal
@required
- (void)onCountScore:(int32_t)score __attribute__((swift_name("onCount(score:)")));
- (void)onExerciseFetchedExercise:(APCExercise *)exercise __attribute__((swift_name("onExerciseFetched(exercise:)")));
- (void)onHoldingTick __attribute__((swift_name("onHoldingTick()")));
- (void)onIntermediateScoreScore:(int32_t)score __attribute__((swift_name("onIntermediateScore(score:)")));
- (void)onTimedOutMsg:(NSString *)msg __attribute__((swift_name("onTimedOut(msg:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ApiClient")))
@interface APCApiClient : APCBase
- (instancetype)initWithApiKey:(NSString *)apiKey baseUrlString:(NSString * _Nullable)baseUrlString __attribute__((swift_name("init(apiKey:baseUrlString:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCApiClientCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getExaminationExaminationId:(int32_t)examinationId completionHandler:(void (^)(APCExamination * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getExamination(examinationId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getExerciseExerciseId:(int32_t)exerciseId completionHandler:(void (^)(APCExercise * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getExercise(exerciseId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPostureExerciseId:(int32_t)exerciseId completionHandler:(void (^)(APCPoseDefinition * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getPosture(exerciseId:completionHandler:)")));
@property (readonly) BOOL isB2C __attribute__((swift_name("isB2C")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ApiClient.Companion")))
@interface APCApiClientCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCApiClientCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AtomicRef")))
@interface APCAtomicRef<T> : APCBase
- (instancetype)initWithValue:(T _Nullable)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property T _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol APCKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface APCKotlinEnum<E> : APCBase <APCKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BodyPart")))
@interface APCBodyPart : APCKotlinEnum<APCBodyPart *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) APCBodyPartCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) APCBodyPart *nose __attribute__((swift_name("nose")));
@property (class, readonly) APCBodyPart *neck __attribute__((swift_name("neck")));
@property (class, readonly) APCBodyPart *rightShoulder __attribute__((swift_name("rightShoulder")));
@property (class, readonly) APCBodyPart *rightElbow __attribute__((swift_name("rightElbow")));
@property (class, readonly) APCBodyPart *rightWrist __attribute__((swift_name("rightWrist")));
@property (class, readonly) APCBodyPart *leftShoulder __attribute__((swift_name("leftShoulder")));
@property (class, readonly) APCBodyPart *leftElbow __attribute__((swift_name("leftElbow")));
@property (class, readonly) APCBodyPart *leftWrist __attribute__((swift_name("leftWrist")));
@property (class, readonly) APCBodyPart *midHip __attribute__((swift_name("midHip")));
@property (class, readonly) APCBodyPart *rightHip __attribute__((swift_name("rightHip")));
@property (class, readonly) APCBodyPart *rightKnee __attribute__((swift_name("rightKnee")));
@property (class, readonly) APCBodyPart *rightAnkle __attribute__((swift_name("rightAnkle")));
@property (class, readonly) APCBodyPart *leftHip __attribute__((swift_name("leftHip")));
@property (class, readonly) APCBodyPart *leftKnee __attribute__((swift_name("leftKnee")));
@property (class, readonly) APCBodyPart *leftAnkle __attribute__((swift_name("leftAnkle")));
@property (class, readonly) APCBodyPart *rightEye __attribute__((swift_name("rightEye")));
@property (class, readonly) APCBodyPart *leftEye __attribute__((swift_name("leftEye")));
@property (class, readonly) APCBodyPart *rightEar __attribute__((swift_name("rightEar")));
@property (class, readonly) APCBodyPart *leftEar __attribute__((swift_name("leftEar")));
@property (class, readonly) APCBodyPart *leftPalm __attribute__((swift_name("leftPalm")));
@property (class, readonly) APCBodyPart *rightPalm __attribute__((swift_name("rightPalm")));
+ (APCKotlinArray<APCBodyPart *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<APCBodyPart *> *entries __attribute__((swift_name("entries")));
- (BOOL)isLeft __attribute__((swift_name("isLeft()")));
- (BOOL)isRight __attribute__((swift_name("isRight()")));
@property (readonly) int32_t position __attribute__((swift_name("position")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BodyPart.Companion")))
@interface APCBodyPartCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCBodyPartCompanion *shared __attribute__((swift_name("shared")));
- (APCBodyPart *)fromIntPosition:(int32_t)position __attribute__((swift_name("fromInt(position:)")));
- (NSArray<APCBodyPart *> *)valuesArray __attribute__((swift_name("valuesArray()")));
@end

__attribute__((swift_name("ConstVisualization")))
@protocol APCConstVisualization
@required
@property (readonly) NSArray<APCKotlinPair<APCBodyPart *, APCBodyPart *> *> *BodyJoints __attribute__((swift_name("BodyJoints")));
@property (readonly) float CIRCLE_RADIUS __attribute__((swift_name("CIRCLE_RADIUS")));
@property (readonly) float LINE_WIDTH __attribute__((swift_name("LINE_WIDTH")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Constant")))
@interface APCConstant : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)constant __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCConstant *shared __attribute__((swift_name("shared")));
@property (readonly) float MIN_PART_SCORE __attribute__((swift_name("MIN_PART_SCORE")));
@property (readonly) float MIN_PERSON_SCORE __attribute__((swift_name("MIN_PERSON_SCORE")));
@property (readonly) id<APCConstVisualization> Visualization __attribute__((swift_name("Visualization")));
@end

__attribute__((swift_name("Freezable")))
@interface APCFreezable : APCBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id _Nullable)freezeMe __attribute__((swift_name("freezeMe()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Coordinate")))
@interface APCCoordinate : APCFreezable
- (instancetype)initWithX:(float)x y:(float)y __attribute__((swift_name("init(x:y:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (APCCoordinate *)doCopyX:(float)x y:(float)y __attribute__((swift_name("doCopy(x:y:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property float x __attribute__((swift_name("x")));
@property float y __attribute__((swift_name("y")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Device")))
@interface APCDevice : APCKotlinEnum<APCDevice *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) APCDevice *cpu __attribute__((swift_name("cpu")));
@property (class, readonly) APCDevice *nnapi __attribute__((swift_name("nnapi")));
@property (class, readonly) APCDevice *gpu __attribute__((swift_name("gpu")));
+ (APCKotlinArray<APCDevice *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<APCDevice *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("DistanceCheckListener")))
@protocol APCDistanceCheckListener
@required
- (void)onSuccess __attribute__((swift_name("onSuccess()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DistanceEvaluator")))
@interface APCDistanceEvaluator : APCBase
- (instancetype)initWithListener:(id<APCDistanceCheckListener>)listener __attribute__((swift_name("init(listener:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCDistanceEvaluatorCompanion *companion __attribute__((swift_name("companion")));
- (void)evaluateInputImageWidthPx:(float)inputImageWidthPx inputImageHeightPx:(float)inputImageHeightPx keyPoints:(NSArray<APCKeyPoint *> *)keyPoints personScore:(float)personScore __attribute__((swift_name("evaluate(inputImageWidthPx:inputImageHeightPx:keyPoints:personScore:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DistanceEvaluator.Companion")))
@interface APCDistanceEvaluatorCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCDistanceEvaluatorCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) APCRectF *boundingBoxRect __attribute__((swift_name("boundingBoxRect")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EvalResult")))
@interface APCEvalResult : APCBase
- (instancetype)initWithIsCountUp:(BOOL)isCountUp timeOutFeedback:(APCKotlinPair<NSString *, NSString *> * _Nullable)timeOutFeedback score:(APCFloat * _Nullable)score __attribute__((swift_name("init(isCountUp:timeOutFeedback:score:)"))) __attribute__((objc_designated_initializer));
- (APCEvalResult *)doCopyIsCountUp:(BOOL)isCountUp timeOutFeedback:(APCKotlinPair<NSString *, NSString *> * _Nullable)timeOutFeedback score:(APCFloat * _Nullable)score __attribute__((swift_name("doCopy(isCountUp:timeOutFeedback:score:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL isCountUp __attribute__((swift_name("isCountUp")));
@property (readonly) APCFloat * _Nullable score __attribute__((swift_name("score")));
@property (readonly) APCKotlinPair<NSString *, NSString *> * _Nullable timeOutFeedback __attribute__((swift_name("timeOutFeedback")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EvaluateUtil")))
@interface APCEvaluateUtil : APCBase
@property (class, readonly, getter=companion) APCEvaluateUtilCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EvaluateUtil.Companion")))
@interface APCEvaluateUtilCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCEvaluateUtilCompanion *shared __attribute__((swift_name("shared")));
- (float)angleBetweenThreePointsStart:(APCCoordinate *)start middle:(APCCoordinate *)middle end:(APCCoordinate *)end __attribute__((swift_name("angleBetweenThreePoints(start:middle:end:)")));
- (float)angleBetweenTwoPointsCenter:(APCCoordinate *)center other:(APCCoordinate *)other __attribute__((swift_name("angleBetweenTwoPoints(center:other:)")));
- (NSArray<APCKeyPoint *> *)flipKeypointsHorKeypoints:(NSArray<APCKeyPoint *> *)keypoints __attribute__((swift_name("flipKeypointsHor(keypoints:)")));
- (NSArray<APCKeyPoint *> *)flipKeypointsHorInCanvasKeypoints:(NSArray<APCKeyPoint *> *)keypoints width:(int32_t)width __attribute__((swift_name("flipKeypointsHorInCanvas(keypoints:width:)")));
- (BOOL)isJointWellVisibleKeypoints:(NSArray<APCKeyPoint *> *)keypoints joints:(APCKotlinArray<APCBodyPart *> *)joints __attribute__((swift_name("isJointWellVisible(keypoints:joints:)")));
- (NSArray<APCKeyPoint *> *)switchBodyPartHorKeyPoints:(NSMutableArray<APCKeyPoint *> *)keyPoints __attribute__((swift_name("switchBodyPartHor(keyPoints:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Evaluator")))
@interface APCEvaluator : APCBase
- (instancetype)initWithExerciseId:(int32_t)exerciseId exercise:(APCPoseDefinition *)exercise listener:(id<APCAlyceposeListenerInternal>)listener __attribute__((swift_name("init(exerciseId:exercise:listener:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCEvaluatorCompanion *companion __attribute__((swift_name("companion")));
- (APCEvalResult * _Nullable)evaluateKeyPoints:(NSArray<APCKeyPoint *> *)keyPoints personScore:(float)personScore __attribute__((swift_name("evaluate(keyPoints:personScore:)")));
- (void)terminate __attribute__((swift_name("terminate()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Evaluator.Companion")))
@interface APCEvaluatorCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCEvaluatorCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExaminationEvaluator")))
@interface APCExaminationEvaluator : APCBase
- (instancetype)initWithExamination:(APCExamination *)examination listener:(id<APCExaminationListener>)listener measureDurationSec:(int32_t)measureDurationSec __attribute__((swift_name("init(examination:listener:measureDurationSec:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCExaminationEvaluatorCompanion *companion __attribute__((swift_name("companion")));
- (void)evaluateKeyPoints:(NSArray<APCKeyPoint *> *)keyPoints personScore:(float)personScore __attribute__((swift_name("evaluate(keyPoints:personScore:)")));
- (void)startMeasurement __attribute__((swift_name("startMeasurement()")));
- (void)terminate __attribute__((swift_name("terminate()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExaminationEvaluator.Companion")))
@interface APCExaminationEvaluatorCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCExaminationEvaluatorCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("ExaminationListener")))
@protocol APCExaminationListener
@required
- (void)onFinishedIsSuccess:(BOOL)isSuccess __attribute__((swift_name("onFinished(isSuccess:)")));
- (void)onReady __attribute__((swift_name("onReady()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExerciseType")))
@interface APCExerciseType : APCKotlinEnum<APCExerciseType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) APCExerciseType *stretching __attribute__((swift_name("stretching")));
@property (class, readonly) APCExerciseType *weight __attribute__((swift_name("weight")));
@property (class, readonly) APCExerciseType *cardio __attribute__((swift_name("cardio")));
+ (APCKotlinArray<APCExerciseType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<APCExerciseType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FlipDir")))
@interface APCFlipDir : APCKotlinEnum<APCFlipDir *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) APCFlipDir *normal __attribute__((swift_name("normal")));
@property (class, readonly) APCFlipDir *flipped __attribute__((swift_name("flipped")));
@property (class, readonly) APCFlipDir *any __attribute__((swift_name("any")));
+ (APCKotlinArray<APCFlipDir *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<APCFlipDir *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KeyPoint")))
@interface APCKeyPoint : APCFreezable
- (instancetype)initWithCoordinate:(APCCoordinate *)coordinate score:(float)score __attribute__((swift_name("init(coordinate:score:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (APCKeyPoint *)doCopy __attribute__((swift_name("doCopy()")));
- (APCKeyPoint *)doCopyCoordinate:(APCCoordinate *)coordinate score:(float)score __attribute__((swift_name("doCopy(coordinate:score:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property APCCoordinate *coordinate __attribute__((swift_name("coordinate")));
@property (readonly) float score __attribute__((swift_name("score")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OriginalBodyPart")))
@interface APCOriginalBodyPart : APCKotlinEnum<APCOriginalBodyPart *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) APCOriginalBodyPartCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) APCOriginalBodyPart *nose __attribute__((swift_name("nose")));
@property (class, readonly) APCOriginalBodyPart *leftEye __attribute__((swift_name("leftEye")));
@property (class, readonly) APCOriginalBodyPart *rightEye __attribute__((swift_name("rightEye")));
@property (class, readonly) APCOriginalBodyPart *leftEar __attribute__((swift_name("leftEar")));
@property (class, readonly) APCOriginalBodyPart *rightEar __attribute__((swift_name("rightEar")));
@property (class, readonly) APCOriginalBodyPart *leftShoulder __attribute__((swift_name("leftShoulder")));
@property (class, readonly) APCOriginalBodyPart *rightShoulder __attribute__((swift_name("rightShoulder")));
@property (class, readonly) APCOriginalBodyPart *leftElbow __attribute__((swift_name("leftElbow")));
@property (class, readonly) APCOriginalBodyPart *rightElbow __attribute__((swift_name("rightElbow")));
@property (class, readonly) APCOriginalBodyPart *leftWrist __attribute__((swift_name("leftWrist")));
@property (class, readonly) APCOriginalBodyPart *rightWrist __attribute__((swift_name("rightWrist")));
@property (class, readonly) APCOriginalBodyPart *leftHip __attribute__((swift_name("leftHip")));
@property (class, readonly) APCOriginalBodyPart *rightHip __attribute__((swift_name("rightHip")));
@property (class, readonly) APCOriginalBodyPart *leftKnee __attribute__((swift_name("leftKnee")));
@property (class, readonly) APCOriginalBodyPart *rightKnee __attribute__((swift_name("rightKnee")));
@property (class, readonly) APCOriginalBodyPart *leftAnkle __attribute__((swift_name("leftAnkle")));
@property (class, readonly) APCOriginalBodyPart *rightAnkle __attribute__((swift_name("rightAnkle")));
+ (APCKotlinArray<APCOriginalBodyPart *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<APCOriginalBodyPart *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t position __attribute__((swift_name("position")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OriginalBodyPart.Companion")))
@interface APCOriginalBodyPartCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCOriginalBodyPartCompanion *shared __attribute__((swift_name("shared")));
- (APCOriginalBodyPart *)fromIntPosition:(int32_t)position __attribute__((swift_name("fromInt(position:)")));
- (NSArray<APCOriginalBodyPart *> *)valuesArray __attribute__((swift_name("valuesArray()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Person")))
@interface APCPerson : APCFreezable
- (instancetype)initWithKeyPoints:(NSArray<APCKeyPoint *> *)keyPoints score:(float)score __attribute__((swift_name("init(keyPoints:score:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (APCPerson *)doCopyKeyPoints:(NSArray<APCKeyPoint *> *)keyPoints score:(float)score __attribute__((swift_name("doCopy(keyPoints:score:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<APCKeyPoint *> *keyPoints __attribute__((swift_name("keyPoints")));
@property (readonly) float score __attribute__((swift_name("score")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PoseEvalResult")))
@interface APCPoseEvalResult : APCBase
- (instancetype)initWithIsValid:(BOOL)isValid score:(APCFloat * _Nullable)score flipDir:(APCFlipDir * _Nullable)flipDir feedback:(APCKotlinPair<NSString *, NSString *> * _Nullable)feedback __attribute__((swift_name("init(isValid:score:flipDir:feedback:)"))) __attribute__((objc_designated_initializer));
- (APCPoseEvalResult *)doCopyIsValid:(BOOL)isValid score:(APCFloat * _Nullable)score flipDir:(APCFlipDir * _Nullable)flipDir feedback:(APCKotlinPair<NSString *, NSString *> * _Nullable)feedback __attribute__((swift_name("doCopy(isValid:score:flipDir:feedback:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) APCKotlinPair<NSString *, NSString *> * _Nullable feedback __attribute__((swift_name("feedback")));
@property (readonly) APCFlipDir * _Nullable flipDir __attribute__((swift_name("flipDir")));
@property (readonly) BOOL isValid __attribute__((swift_name("isValid")));
@property (readonly) APCFloat * _Nullable score __attribute__((swift_name("score")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RectF")))
@interface APCRectF : APCBase
- (instancetype)initWithLeft:(float)left top:(float)top right:(float)right bottom:(float)bottom __attribute__((swift_name("init(left:top:right:bottom:)"))) __attribute__((objc_designated_initializer));
- (APCRectF *)doCopyLeft:(float)left top:(float)top right:(float)right bottom:(float)bottom __attribute__((swift_name("doCopy(left:top:right:bottom:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) float bottom __attribute__((swift_name("bottom")));
@property (readonly) float left __attribute__((swift_name("left")));
@property (readonly) float right __attribute__((swift_name("right")));
@property (readonly) float top __attribute__((swift_name("top")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SampleExercise")))
@interface APCSampleExercise : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)sampleExercise __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCSampleExercise *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *Dev __attribute__((swift_name("Dev")));
@property (readonly) NSString *SideBend __attribute__((swift_name("SideBend")));
@property (readonly) NSString *StretchingNeckDown __attribute__((swift_name("StretchingNeckDown")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TorsoAndBodyDistance")))
@interface APCTorsoAndBodyDistance : APCBase
- (instancetype)initWithMaxTorsoYDistance:(float)maxTorsoYDistance maxTorsoXDistance:(float)maxTorsoXDistance maxBodyYDistance:(float)maxBodyYDistance maxBodyXDistance:(float)maxBodyXDistance __attribute__((swift_name("init(maxTorsoYDistance:maxTorsoXDistance:maxBodyYDistance:maxBodyXDistance:)"))) __attribute__((objc_designated_initializer));
- (APCTorsoAndBodyDistance *)doCopyMaxTorsoYDistance:(float)maxTorsoYDistance maxTorsoXDistance:(float)maxTorsoXDistance maxBodyYDistance:(float)maxBodyYDistance maxBodyXDistance:(float)maxBodyXDistance __attribute__((swift_name("doCopy(maxTorsoYDistance:maxTorsoXDistance:maxBodyYDistance:maxBodyXDistance:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) float maxBodyXDistance __attribute__((swift_name("maxBodyXDistance")));
@property (readonly) float maxBodyYDistance __attribute__((swift_name("maxBodyYDistance")));
@property (readonly) float maxTorsoXDistance __attribute__((swift_name("maxTorsoXDistance")));
@property (readonly) float maxTorsoYDistance __attribute__((swift_name("maxTorsoYDistance")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Util")))
@interface APCUtil : APCBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) APCUtilCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Util.Companion")))
@interface APCUtilCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCUtilCompanion *shared __attribute__((swift_name("shared")));
- (int64_t)currentTimeMs __attribute__((swift_name("currentTimeMs()")));
- (id _Nullable)freezeA:(id _Nullable)a __attribute__((swift_name("freeze(a:)")));
- (void)logDTag:(NSString *)tag msg:(NSString *)msg __attribute__((swift_name("logD(tag:msg:)")));
- (void)logETag:(NSString *)tag msg:(NSString *)msg __attribute__((swift_name("logE(tag:msg:)")));
- (void)logITag:(NSString *)tag msg:(NSString *)msg __attribute__((swift_name("logI(tag:msg:)")));
- (void)logVTag:(NSString *)tag msg:(NSString *)msg __attribute__((swift_name("logV(tag:msg:)")));
- (void)logWTag:(NSString *)tag msg:(NSString *)msg __attribute__((swift_name("logW(tag:msg:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("VisualizationUtils")))
@interface APCVisualizationUtils : APCBase
- (instancetype)initWithSurface:(UIImageView *)surface __attribute__((swift_name("init(surface:)"))) __attribute__((objc_designated_initializer));
- (void)drawSkeletonInputImage:(UIImage *)inputImage person:(APCPerson *)person __attribute__((swift_name("drawSkeleton(inputImage:person:)")));
@property (readonly) UIImageView *surface __attribute__((swift_name("surface")));
@end

__attribute__((swift_name("ConditionBase")))
@protocol APCConditionBase
@required
@property NSString * _Nullable feedback __attribute__((swift_name("feedback")));
@property APCInt * _Nullable priority __attribute__((swift_name("priority")));
@end

__attribute__((swift_name("Angle")))
@protocol APCAngle <APCConditionBase>
@required
- (APCFloat * _Nullable)evaluateKeypoints:(NSArray<APCKeyPoint *> *)keypoints start:(APCBodyPart * _Nullable)start center:(APCBodyPart *)center end:(APCBodyPart *)end __attribute__((swift_name("evaluate(keypoints:start:center:end:)")));
@property float angle __attribute__((swift_name("angle")));
@property float angleMargin __attribute__((swift_name("angleMargin")));
@property APCBodyPart *vcenter __attribute__((swift_name("vcenter")));
@property APCBodyPart *vend __attribute__((swift_name("vend")));
@property APCBodyPart * _Nullable vstart __attribute__((swift_name("vstart")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AbsoluteAngle")))
@interface APCAbsoluteAngle : APCBase <APCAngle>
- (instancetype)initWith__center:(int32_t)__center __end:(int32_t)__end __attribute__((swift_name("init(__center:__end:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCAbsoluteAngleCompanion *companion __attribute__((swift_name("companion")));
- (APCAbsoluteAngle *)doCopy__center:(int32_t)__center __end:(int32_t)__end __attribute__((swift_name("doCopy(__center:__end:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="c")
*/
@property (readonly) int32_t __center __attribute__((swift_name("__center")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="e")
*/
@property (readonly) int32_t __end __attribute__((swift_name("__end")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="a")
*/
@property float angle __attribute__((swift_name("angle")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="m")
*/
@property float angleMargin __attribute__((swift_name("angleMargin")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="f")
*/
@property NSString * _Nullable feedback __attribute__((swift_name("feedback")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="p")
*/
@property APCInt * _Nullable priority __attribute__((swift_name("priority")));
@property APCBodyPart *vcenter __attribute__((swift_name("vcenter")));
@property APCBodyPart *vend __attribute__((swift_name("vend")));
@property APCBodyPart * _Nullable vstart __attribute__((swift_name("vstart")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AbsoluteAngle.Companion")))
@interface APCAbsoluteAngleCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCAbsoluteAngleCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AuthRequestBody")))
@interface APCAuthRequestBody : APCBase
- (instancetype)initWithApiKey:(NSString *)apiKey __attribute__((swift_name("init(apiKey:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCAuthRequestBodyCompanion *companion __attribute__((swift_name("companion")));
- (APCAuthRequestBody *)doCopyApiKey:(NSString *)apiKey __attribute__((swift_name("doCopy(apiKey:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *apiKey __attribute__((swift_name("apiKey")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AuthRequestBody.Companion")))
@interface APCAuthRequestBodyCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCAuthRequestBodyCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AuthResponse")))
@interface APCAuthResponse : APCBase
- (instancetype)initWithToken:(NSString *)token route:(NSString * _Nullable)route __attribute__((swift_name("init(token:route:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCAuthResponseCompanion *companion __attribute__((swift_name("companion")));
- (APCAuthResponse *)doCopyToken:(NSString *)token route:(NSString * _Nullable)route __attribute__((swift_name("doCopy(token:route:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="path")
*/
@property (readonly) NSString * _Nullable route __attribute__((swift_name("route")));
@property (readonly) NSString *token __attribute__((swift_name("token")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AuthResponse.Companion")))
@interface APCAuthResponseCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCAuthResponseCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Category")))
@interface APCCategory : APCKotlinEnum<APCCategory *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) APCCategoryCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) APCCategory *stretching __attribute__((swift_name("stretching")));
@property (class, readonly) APCCategory *cardio __attribute__((swift_name("cardio")));
@property (class, readonly) APCCategory *weight __attribute__((swift_name("weight")));
+ (APCKotlinArray<APCCategory *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<APCCategory *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Category.Companion")))
@interface APCCategoryCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCCategoryCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializerTypeParamsSerializers:(APCKotlinArray<id<APCKotlinx_serialization_coreKSerializer>> *)typeParamsSerializers __attribute__((swift_name("serializer(typeParamsSerializers:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Condition")))
@interface APCCondition : APCBase
- (instancetype)initWithPosition:(APCKotlinArray<APCPosition *> * _Nullable)position angleRel:(APCKotlinArray<APCRelativeAngle *> * _Nullable)angleRel angleAbs:(APCKotlinArray<APCAbsoluteAngle *> * _Nullable)angleAbs __attribute__((swift_name("init(position:angleRel:angleAbs:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCConditionCompanion *companion __attribute__((swift_name("companion")));
- (APCCondition *)doCopyPosition:(APCKotlinArray<APCPosition *> * _Nullable)position angleRel:(APCKotlinArray<APCRelativeAngle *> * _Nullable)angleRel angleAbs:(APCKotlinArray<APCAbsoluteAngle *> * _Nullable)angleAbs __attribute__((swift_name("doCopy(position:angleRel:angleAbs:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="aa")
*/
@property (readonly) APCKotlinArray<APCAbsoluteAngle *> * _Nullable angleAbs __attribute__((swift_name("angleAbs")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="ar")
*/
@property (readonly) APCKotlinArray<APCRelativeAngle *> * _Nullable angleRel __attribute__((swift_name("angleRel")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="pn")
*/
@property (readonly) APCKotlinArray<APCPosition *> * _Nullable position __attribute__((swift_name("position")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Condition.Companion")))
@interface APCConditionCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCConditionCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Examination")))
@interface APCExamination : APCBase
- (instancetype)initWithBad:(APCKotlinArray<APCInt *> *)bad useMaxValue:(BOOL)useMaxValue angleRangeToIgnore:(APCKotlinArray<APCInt *> *)angleRangeToIgnore bone:(APCKotlinArray<APCInt *> *)bone initialPose:(APCInitialPose *)initialPose __attribute__((swift_name("init(bad:useMaxValue:angleRangeToIgnore:bone:initialPose:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCExaminationCompanion *companion __attribute__((swift_name("companion")));
- (APCExamination *)doCopyBad:(APCKotlinArray<APCInt *> *)bad useMaxValue:(BOOL)useMaxValue angleRangeToIgnore:(APCKotlinArray<APCInt *> *)angleRangeToIgnore bone:(APCKotlinArray<APCInt *> *)bone initialPose:(APCInitialPose *)initialPose __attribute__((swift_name("doCopy(bad:useMaxValue:angleRangeToIgnore:bone:initialPose:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="el")
*/
@property (readonly) APCKotlinArray<APCInt *> *angleRangeToIgnore __attribute__((swift_name("angleRangeToIgnore")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="bd")
*/
@property (readonly) APCKotlinArray<APCInt *> *bad __attribute__((swift_name("bad")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="nb")
*/
@property (readonly) APCKotlinArray<APCInt *> *bone __attribute__((swift_name("bone")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="ii")
*/
@property (readonly) APCInitialPose *initialPose __attribute__((swift_name("initialPose")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="xm")
*/
@property (readonly) BOOL useMaxValue __attribute__((swift_name("useMaxValue")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Examination.Companion")))
@interface APCExaminationCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCExaminationCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Exercise")))
@interface APCExercise : APCBase
- (instancetype)initWithId:(int32_t)id title:(NSString *)title category:(APCCategory *)category difficulty:(int32_t)difficulty previewVideo:(NSString *)previewVideo exerciseVideo:(NSString *)exerciseVideo __attribute__((swift_name("init(id:title:category:difficulty:previewVideo:exerciseVideo:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCExerciseCompanion *companion __attribute__((swift_name("companion")));
- (APCExercise *)doCopyId:(int32_t)id title:(NSString *)title category:(APCCategory *)category difficulty:(int32_t)difficulty previewVideo:(NSString *)previewVideo exerciseVideo:(NSString *)exerciseVideo __attribute__((swift_name("doCopy(id:title:category:difficulty:previewVideo:exerciseVideo:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) APCCategory *category __attribute__((swift_name("category")));
@property (readonly) int32_t difficulty __attribute__((swift_name("difficulty")));
@property (readonly) NSString *exerciseVideo __attribute__((swift_name("exerciseVideo")));
@property (readonly) int32_t id __attribute__((swift_name("id")));
@property (readonly) NSString *previewVideo __attribute__((swift_name("previewVideo")));
@property (readonly) NSString *title __attribute__((swift_name("title")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Exercise.Companion")))
@interface APCExerciseCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCExerciseCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InitialPose")))
@interface APCInitialPose : APCBase
- (instancetype)initWithCenter:(int32_t)center end:(int32_t)end angle:(int32_t)angle angleMargin:(int32_t)angleMargin __attribute__((swift_name("init(center:end:angle:angleMargin:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCInitialPoseCompanion *companion __attribute__((swift_name("companion")));
- (APCInitialPose *)doCopyCenter:(int32_t)center end:(int32_t)end angle:(int32_t)angle angleMargin:(int32_t)angleMargin __attribute__((swift_name("doCopy(center:end:angle:angleMargin:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="v")
*/
@property (readonly) int32_t angle __attribute__((swift_name("angle")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="m")
*/
@property (readonly) int32_t angleMargin __attribute__((swift_name("angleMargin")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="s")
*/
@property (readonly) int32_t center __attribute__((swift_name("center")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="e")
*/
@property (readonly) int32_t end __attribute__((swift_name("end")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InitialPose.Companion")))
@interface APCInitialPoseCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCInitialPoseCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Pose")))
@interface APCPose : APCBase
- (instancetype)initWithId:(int32_t)id condition:(APCCondition *)condition allowFlipH:(APCBoolean * _Nullable)allowFlipH __attribute__((swift_name("init(id:condition:allowFlipH:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCPoseCompanion *companion __attribute__((swift_name("companion")));
- (APCPose *)doCopyId:(int32_t)id condition:(APCCondition *)condition allowFlipH:(APCBoolean * _Nullable)allowFlipH __attribute__((swift_name("doCopy(id:condition:allowFlipH:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (APCPoseEvalResult *)evaluateKeyPoints:(NSArray<APCKeyPoint *> *)keyPoints flipDir:(APCFlipDir *)flipDir exerciseId:(int32_t)exerciseId __attribute__((swift_name("evaluate(keyPoints:flipDir:exerciseId:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="mr")
*/
@property (readonly) APCBoolean * _Nullable allowFlipH __attribute__((swift_name("allowFlipH")));
@property (readonly) APCCondition *condition __attribute__((swift_name("condition")));
@property (readonly) int32_t id __attribute__((swift_name("id")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Pose.Companion")))
@interface APCPoseCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCPoseCompanion *shared __attribute__((swift_name("shared")));
- (NSString *)getCorrectionVoiceUrlExerciseId:(int32_t)exerciseId priorityIndex:(int32_t)priorityIndex __attribute__((swift_name("getCorrectionVoiceUrl(exerciseId:priorityIndex:)")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PoseDecoder")))
@interface APCPoseDecoder : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)poseDecoder __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCPoseDecoder *shared __attribute__((swift_name("shared")));
- (APCPoseDefinition *)decodePosesText:(NSString *)posesText __attribute__((swift_name("decode(posesText:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PoseDefinition")))
@interface APCPoseDefinition : APCBase
- (instancetype)initWithCategory:(APCCategory *)category pos:(APCKotlinArray<APCPose *> *)pos evalLikeWeight:(APCBoolean * _Nullable)evalLikeWeight __attribute__((swift_name("init(category:pos:evalLikeWeight:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCPoseDefinitionCompanion *companion __attribute__((swift_name("companion")));
- (APCPoseDefinition *)doCopyCategory:(APCCategory *)category pos:(APCKotlinArray<APCPose *> *)pos evalLikeWeight:(APCBoolean * _Nullable)evalLikeWeight __attribute__((swift_name("doCopy(category:pos:evalLikeWeight:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) APCCategory *category __attribute__((swift_name("category")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="elw")
*/
@property (readonly) APCBoolean * _Nullable evalLikeWeight __attribute__((swift_name("evalLikeWeight")));
@property (readonly) APCKotlinArray<APCPose *> *pos __attribute__((swift_name("pos")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PoseDefinition.Companion")))
@interface APCPoseDefinitionCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCPoseDefinitionCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Position")))
@interface APCPosition : APCBase <APCConditionBase>
- (instancetype)initWithIsHorizontal:(APCBoolean * _Nullable)isHorizontal partIds:(APCKotlinArray<APCInt *> *)partIds __attribute__((swift_name("init(isHorizontal:partIds:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCPositionCompanion *companion __attribute__((swift_name("companion")));
- (APCPosition *)doCopyIsHorizontal:(APCBoolean * _Nullable)isHorizontal partIds:(APCKotlinArray<APCInt *> *)partIds __attribute__((swift_name("doCopy(isHorizontal:partIds:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isValidKeypoints:(NSArray<APCKeyPoint *> *)keypoints __attribute__((swift_name("isValid(keypoints:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.Transient
*/
@property NSString * _Nullable feedback __attribute__((swift_name("feedback")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="h")
*/
@property (readonly) APCBoolean * _Nullable isHorizontal __attribute__((swift_name("isHorizontal")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="i")
*/
@property (readonly) APCKotlinArray<APCInt *> *partIds __attribute__((swift_name("partIds")));

/**
 * @note annotations
 *   kotlinx.serialization.Transient
*/
@property APCInt * _Nullable priority __attribute__((swift_name("priority")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Position.Companion")))
@interface APCPositionCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCPositionCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RelativeAngle")))
@interface APCRelativeAngle : APCBase <APCAngle>
- (instancetype)initWith__start:(int32_t)__start __center:(int32_t)__center __end:(int32_t)__end __attribute__((swift_name("init(__start:__center:__end:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) APCRelativeAngleCompanion *companion __attribute__((swift_name("companion")));
- (APCRelativeAngle *)doCopy__start:(int32_t)__start __center:(int32_t)__center __end:(int32_t)__end __attribute__((swift_name("doCopy(__start:__center:__end:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="c")
*/
@property (readonly) int32_t __center __attribute__((swift_name("__center")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="e")
*/
@property (readonly) int32_t __end __attribute__((swift_name("__end")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="s")
*/
@property (readonly) int32_t __start __attribute__((swift_name("__start")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="a")
*/
@property float angle __attribute__((swift_name("angle")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="m")
*/
@property float angleMargin __attribute__((swift_name("angleMargin")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="f")
*/
@property NSString * _Nullable feedback __attribute__((swift_name("feedback")));

/**
 * @note annotations
 *   kotlinx.serialization.SerialName(value="p")
*/
@property APCInt * _Nullable priority __attribute__((swift_name("priority")));
@property APCBodyPart *vcenter __attribute__((swift_name("vcenter")));
@property APCBodyPart *vend __attribute__((swift_name("vend")));
@property APCBodyPart * _Nullable vstart __attribute__((swift_name("vstart")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RelativeAngle.Companion")))
@interface APCRelativeAngleCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCRelativeAngleCompanion *shared __attribute__((swift_name("shared")));
- (id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtilKt")))
@interface APCUtilKt : APCBase
@property (class, readonly) BOOL IS_DEBUG __attribute__((swift_name("IS_DEBUG")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface APCKotlinThrowable : APCBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (APCKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) APCKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface APCKotlinException : APCKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface APCKotlinRuntimeException : APCKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface APCKotlinIllegalStateException : APCKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface APCKotlinCancellationException : APCKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(APCKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface APCKotlinEnumCompanion : APCBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) APCKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface APCKotlinArray<T> : APCBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(APCInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<APCKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface APCKotlinPair<__covariant A, __covariant B> : APCBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (APCKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol APCKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<APCKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<APCKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol APCKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<APCKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<APCKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol APCKotlinx_serialization_coreKSerializer <APCKotlinx_serialization_coreSerializationStrategy, APCKotlinx_serialization_coreDeserializationStrategy>
@required
@end

__attribute__((swift_name("KotlinIterator")))
@protocol APCKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol APCKotlinx_serialization_coreEncoder
@required
- (id<APCKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<APCKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<APCKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<APCKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<APCKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) APCKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol APCKotlinx_serialization_coreSerialDescriptor
@required

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSArray<id<APCKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<APCKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSArray<id<APCKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) APCKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol APCKotlinx_serialization_coreDecoder
@required
- (id<APCKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<APCKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (APCKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<APCKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<APCKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) APCKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol APCKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<APCKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<APCKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<APCKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) APCKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface APCKotlinx_serialization_coreSerializersModule : APCBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<APCKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<APCKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<APCKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<APCKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<APCKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<APCKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<APCKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<APCKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol APCKotlinAnnotation
@required
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface APCKotlinx_serialization_coreSerialKind : APCBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol APCKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<APCKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<APCKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<APCKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<APCKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) APCKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface APCKotlinNothing : APCBase
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol APCKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<APCKotlinKClass>)kClass provider:(id<APCKotlinx_serialization_coreKSerializer> (^)(NSArray<id<APCKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<APCKotlinKClass>)kClass serializer:(id<APCKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<APCKotlinKClass>)baseClass actualClass:(id<APCKotlinKClass>)actualClass actualSerializer:(id<APCKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<APCKotlinKClass>)baseClass defaultDeserializerProvider:(id<APCKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));
- (void)polymorphicDefaultDeserializerBaseClass:(id<APCKotlinKClass>)baseClass defaultDeserializerProvider:(id<APCKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));
- (void)polymorphicDefaultSerializerBaseClass:(id<APCKotlinKClass>)baseClass defaultSerializerProvider:(id<APCKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol APCKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol APCKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol APCKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol APCKotlinKClass <APCKotlinKDeclarationContainer, APCKotlinKAnnotatedElement, APCKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
